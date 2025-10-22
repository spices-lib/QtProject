#pragma once
#include <QObject>

class QmlJSCaller : public QObject
{
    Q_OBJECT

public:

    explicit QmlJSCaller(QObject *parent = nullptr);

    Q_INVOKABLE void cppMethod(QString message);

    void setQmlRootObject(QObject* value);

private:

    void callJSMethod(QString param);

    QObject* m_qmlRootObject;
};



