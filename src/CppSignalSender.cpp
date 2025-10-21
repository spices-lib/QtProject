#include "CppSignalSender.h"

CppSignalSender::CppSignalSender(QObject *parent)
    : QObject(parent)
    , m_Timer(new QTimer(this))
    , m_Value(0)
{
    connect(&m_Timer, &QTimer::timeout, [=](){
        ++m_Value;
        emit cppTimer(QString::number(m_Value));
    });

    m_Timer.start(1000);
}

void CppSignalSender::cppSlot() {
    emit callQml("Information from C++");
}
