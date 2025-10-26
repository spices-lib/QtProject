#pragma once
#include <QtQuick>
#include <QtQml>
#include <qnetworkrequestfactory.h>
#include <qrestaccessmanager.h>

class AppWrapper : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QStringList posts READ posts NOTIFY postsChanged)

public:

    explicit AppWrapper(QObject* parent = nullptr);
    ~AppWrapper() override = default;

    const QStringList& posts() const { return mPosts; }

signals:

    void postsChanged();

public slots:

    void fetchPosts();
    void removeLast();

private slots:

    void dataReadyRead();
    void dataReadFinished();

private:

    std::unique_ptr<QNetworkAccessManager> mNetManager;
    std::unique_ptr<QNetworkRequestFactory> mFactory;
    std::unique_ptr<QRestAccessManager> mResetAccessManager;
    QNetworkReply* mNetReply;
    QByteArray mDataBuffer;
    QStringList mPosts;
    QQmlApplicationEngine mEngine;

};