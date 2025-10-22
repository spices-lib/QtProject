#include "QmlJSCaller.h"
#include <QDebug>
#include <QVariant>

QmlJSCaller::QmlJSCaller(QObject *parent)
    : QObject(parent)
    , m_qmlRootObject(nullptr)
{

}

void QmlJSCaller::cppMethod(QString message) {
    qDebug() << "Cpp method called with message: " << message;
    callJSMethod(message);
}

void QmlJSCaller::setQmlRootObject(QObject *value) {
    m_qmlRootObject = value;
}

void QmlJSCaller::callJSMethod(QString param) {
    QVariant returnedValue;
    QVariant cppParameter = QVariant::fromValue(param);

    // invoke qml method
    QMetaObject::invokeMethod(m_qmlRootObject, "qmlJSFunction",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, cppParameter));

    qDebug() << "Returned value from qml: " << returnedValue.toString();
}
