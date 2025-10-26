#pragma once
#include <QtQuick>
#include <QtQml>
#include <QUrl>
#include <QDate>
#include <QPoint>
#include <QFont>
#include <QColor>
#include <QSize>
#include <QRect>

class CppClass : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:

    explicit CppClass(QObject* parent = nullptr);

signals:

    void sendInt(int v);
    void sendDouble(double v);
    void sendBool(bool v);
    void sendReal(qreal v);
    void sendFloat(float v);
    void sendString(QString v);
    void sendUrl(QUrl v);
    void sendColor(QColor v);
    void sendFont(QFont v);
    void sendData(QDate v);
    void sendPoint(QPoint v);
    void sendSize(QSize v);
    void sendRect(QRect v);

public slots:

    void cppSlot();

    void receivePoint(QPoint point);
    void receiveRect(QRect rect);

};