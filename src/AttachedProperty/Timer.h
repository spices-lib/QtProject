#pragma once
#include <QtQuick>
#include <QtQml>
#include "TimerAttached.h"

class Timer : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit Timer(QObject *parent = nullptr);

    static TimerAttached* qmlAttachedProperties(QObject *object);

};

QML_DECLARE_TYPEINFO(Timer, QML_HAS_ATTACHED_PROPERTIES)