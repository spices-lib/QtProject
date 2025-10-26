#include "AppWrapper.h"
#include <QDebug>

AppWrapper::AppWrapper(QObject *parent)
    : QObject(parent)
    , mNetManager(std::make_unique<QNetworkAccessManager>())
{}

void AppWrapper::fetchPosts() {
    const QUrl API_URL("https://jsonplaceholder.typicode.com/posts");

    QNetworkRequest request;
    request.setUrl(API_URL);

    mNetReply = mNetManager->get(request);

    connect(mNetReply, &QNetworkReply::readyRead, this, &AppWrapper::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataReadFinished);
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

