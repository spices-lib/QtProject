#include "Player.h"
#include <QDebug>

Player::Player(QObject *parent)
    : QObject(parent)
{}

void Player::setName(QString name) {
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged();
}

void Player::setPlaying(bool playing) {
    if (m_playing == playing)
        return;

    m_playing = playing;
    emit playingChanged();
}

void Player::setPosition(QString position) {
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged();
}
