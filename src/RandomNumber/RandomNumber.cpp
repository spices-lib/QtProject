#include "RandomNumber.h"

RandomNumber::RandomNumber(QObject *parent)
    : QObject(parent)
    , m_timer(new QTimer(this))
    , m_maxValue(100)
{
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    m_timer->start(1500);
}

void RandomNumber::setTarget(const QQmlProperty & p) {
    m_property = p;
}

void RandomNumber::setMaxValue(int maxValue) {
    if (m_maxValue != maxValue) {
        m_maxValue = maxValue;
        emit maxValueChanged();
    }
}

void RandomNumber::updateValue() {
    m_property.write(QRandomGenerator::global()->bounded(m_maxValue));
}
