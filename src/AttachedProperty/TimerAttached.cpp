#include "TimerAttached.h"

TimerAttached::TimerAttached(QObject *parent)
    : QObject(parent)
    , m_timer(new QTimer(this))
    , m_interval(2000)
    , m_running(false)
{
    connect(m_timer, &QTimer::timeout, this, [=](){
        emit timeout();
    });
}

void TimerAttached::setInterval(int interval) {
    if (m_interval != interval) {
        m_interval = interval;
        emit intervalChanged();
    }
}

void TimerAttached::setRunning(bool running) {
    if (m_running != running) {
        m_running = running;
        emit runningChanged();
        if (m_running) {
            m_timer->start(m_interval);
        } else {
            m_timer->stop();
        }
    }
}
