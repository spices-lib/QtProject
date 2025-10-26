#pragma once
#include <QtQuick>
#include <QtQml>

class Singleton : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:

    explicit Singleton(QObject* parent = nullptr);

    Q_INVOKABLE void doSomething() const
    {
        qDebug() << "Doing something...";
    }

};