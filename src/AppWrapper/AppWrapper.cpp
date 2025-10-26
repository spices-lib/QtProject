#include "AppWrapper.h"
#include <QDebug>

AppWrapper::AppWrapper(QObject *parent)
    : QObject(parent)
    , mNetManager(std::make_unique<QNetworkAccessManager>())
    , mResetAccessManager(std::make_unique<QRestAccessManager>(mNetManager.get()))
    , mFactory(std::make_unique<QNetworkRequestFactory>())
{
    mFactory->setBaseUrl(QUrl("https://jsonplaceholder.typicode.com"));
}

void AppWrapper::fetchPosts() {
    mResetAccessManager->get(mFactory->createRequest("/posts"), this, [=](QRestReply& reply){
        if (!reply.isSuccess()) {
            return;
        }

        auto doc = reply.readJson();
        QJsonArray array = doc.value().array();

        for (int i = 0; i < 10; i++) {
            QJsonValue item = array.at(i);
            QJsonObject obj = item.toObject();
            auto map = obj.toVariantMap();
            auto title = map["title"].toString();
            mPosts.append(title);
        }

        emit postsChanged();
    });

}

void AppWrapper::removeLast() {
    if (!mPosts.isEmpty()) {
        mPosts.removeLast();
        emit postsChanged();
    }
}

void AppWrapper::dataReadyRead() {
    mDataBuffer.append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished() {
    if (mNetReply->error()) {
        qDebug() << "Error: " << mNetReply->errorString();
    }
    else {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(mDataBuffer);

        QJsonArray array = jsonDoc.array();
        for (int i = 0; i < 10; i++) {
            QJsonValue item = array.at(i);
            QJsonObject obj = item.toObject();
            auto map = obj.toVariantMap();
            auto title = map["title"].toString();
            mPosts.append(title);
        }

        mDataBuffer.clear();
    }

    emit postsChanged();
}

