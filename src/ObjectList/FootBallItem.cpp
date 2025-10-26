#include "FootBallItem.h"

FootBallItem::FootBallItem(QObject *parent) : QObject(parent) {

}

QQmlListProperty<Player> FootBallItem::players() {
    return QQmlListProperty<Player>(
        this,
        this,
        &FootBallItem::appendPlayer,
        &FootBallItem::playerCount,
        &FootBallItem::player,
        &FootBallItem::clearPlayers
    );
}

void FootBallItem::setTitle(QString title) {
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged();
}

void FootBallItem::setCoatch(QString coatch) {
    if (m_coatch == coatch)
        return;

    m_coatch = coatch;
    emit coatchChanged();
}

void FootBallItem::setCaptain(Player *captain) {
    if (m_captain == captain)
        return;

    m_captain = captain;
    emit captainChanged();
}

void FootBallItem::appendPlayerCustom(Player *player) {
    qDebug() << "Adding player to vector" << player->name();
    m_players.push_back(player);
}

int FootBallItem::playerCountCustom() const {
    return m_players.count();
}

Player *FootBallItem::playerCustom(int index) const {
    return m_players.at(index);
}

void FootBallItem::clearPlayersCustom() {
    m_players.clear();
}

void FootBallItem::appendPlayer(QQmlListProperty<Player> *list, Player *player) {
    reinterpret_cast<FootBallItem*>(list->data)->appendPlayerCustom(player);
}

qsizetype FootBallItem::playerCount(QQmlListProperty<Player> *list) {
    return reinterpret_cast<FootBallItem*>(list->data)->playerCountCustom();
}

Player *FootBallItem::player(QQmlListProperty<Player> *list, qsizetype index) {
    return reinterpret_cast<FootBallItem*>(list->data)->playerCustom(index);
}

void FootBallItem::clearPlayers(QQmlListProperty<Player> *list) {
    reinterpret_cast<FootBallItem*>(list->data)->clearPlayersCustom();
}
