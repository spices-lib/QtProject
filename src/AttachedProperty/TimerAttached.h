#pragma once
#include <QtQuick>
#include <QtQml>

class TimerAttached : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Cannot create")
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

public:

    explicit TimerAttached(QObject* parent = nullptr);

    int interval() const { return m_interval; }
    bool running() const { return m_running; }

    void setInterval(int interval);
    void setRunning(bool running);

 signals:

    void timeout();
    void intervalChanged();
    void runningChanged();

private:

    QTimer* m_timer;
    int m_interval;
    bool m_running;
};