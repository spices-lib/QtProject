#include "PlayerDetails.h"

PlayerDetails::PlayerDetails(QObject *parent) : QObject(parent) {

}


void PlayerDetails::setHeight(qreal height) {
    if (m_height == height)
        return;

    m_height = height;
    emit heightChanged();
}


void PlayerDetails::setWeight(qreal weight) {
    if (m_weight == weight)
        return;

    m_weight = weight;
    emit weightChanged();
}

void PlayerDetails::setSpeed(qreal speed) {
    if (m_speed == speed)
        return;

    m_speed = speed;
    emit speedChanged();
}
