#include "CppClass.h"
#include <QDebug>

CppClass::CppClass(QObject *parent)
    : QObject(parent)
{}

void CppClass::cppSlot() {
    qDebug() << "cpp Slot called";

    emit sendInt(42);
    emit sendDouble(43.232);
    emit sendBool(true);
    emit sendReal(5);
    emit sendFloat(418.0f);
    emit sendString("Hello");
    emit sendUrl(QUrl("in.in.me"));
    emit sendColor(QColor(1, 2, 3, 4));
    emit sendFont(QFont("Times"));
    emit sendData(QDate::currentDate());
    emit sendTime(QTime::currentTime());
    emit sendDataTime(QDateTime::currentDateTime());
    emit sendPoint(QPoint(100, 100));
    emit sendSize(QSize(200, 200));
    emit sendRect(QRect(100, 100, 100, 100));

}

void CppClass::receivePoint(QPoint point) {

}

void CppClass::receiveRect(QRect rect) {

}

void CppClass::qmlArrayToCpp(QVector<QString> vector) {
    qDebug() << vector;
}

QVector<QString> CppClass::retrieveString() {

    QVector<QString> array;
    array.push_back("Hello");
    array.push_back("Hello1");

    return array;
}

void CppClass::qmlToCpp(QVariantList list, QVariantMap map) {
    qDebug() << list << ", " <<  map;
}

QVariantMap CppClass::retrieveMap() {

    QVariantMap map;
    map["1"] = "dawdaw";
    map["2"] = 415.0f;

    return map;
}

QVariantList CppClass::retrieveList() {

    QVariantList list;
    list << "Hello" << "World" << 42 << 42.0f << QColor(1, 2, 3, 4);

    return list;
}



