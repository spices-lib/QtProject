#include "Timer.h"

Timer::Timer(QObject *parent) : QObject(parent) {

}

TimerAttached *Timer::qmlAttachedProperties(QObject *object) {
    return new TimerAttached(object);
}
