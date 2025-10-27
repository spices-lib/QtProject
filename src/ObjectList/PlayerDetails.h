#pragma once
#include <QtQuick>
#include <QtQml>

class PlayerDetails : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged)

public:

    explicit PlayerDetails(QObject *parent = nullptr);

    qreal height() const { return m_height; }
    qreal weight() const { return m_weight; }
    qreal speed() const { return m_speed; }

    void setHeight(qreal height);

    void setWeight(qreal weight);

    void setSpeed(qreal speed);

signals:

    void heightChanged();
    void weightChanged();
    void speedChanged();

private:

    qreal m_height;
    qreal m_weight;
    qreal m_speed;

};



