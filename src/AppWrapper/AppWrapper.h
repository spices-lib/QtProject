#pragma once
#include <QtQuick>
#include <QtQml>

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
    QNetworkReply* mNetReply;
    QByteArray mDataBuffer;
    QStringList mPosts;
    QQmlApplicationEngine mEngine;

};