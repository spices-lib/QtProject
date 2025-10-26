#pragma once
#include <QtQuick>
#include <QtQml>
#include "Player.h"

class FootBallItem : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coatch READ coatch WRITE setCoatch NOTIFY coatchChanged)
    Q_PROPERTY(Player* captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players NOTIFY playersChanged)

public:

    explicit FootBallItem(QObject *parent = nullptr);

    QString title() const { return m_title; }
    QString coatch() const { return m_coatch; }
    Player* captain() const { return m_captain; }
    QQmlListProperty<Player> players();

    void setTitle(QString title);
    void setCoatch(QString coatch);
    void setCaptain(Player* captain);

    void appendPlayerCustom(Player* player);
    int playerCountCustom() const;
    Player* playerCustom(int index) const;
    void clearPlayersCustom();

signals:

    void titleChanged();
    void coatchChanged();
    void captainChanged();
    void playersChanged();

private:

    static void appendPlayer(QQmlListProperty<Player>* list, Player* player);
    static qsizetype playerCount(QQmlListProperty<Player>* list);
    static Player* player(QQmlListProperty<Player>* list, qsizetype index);
    static void clearPlayers(QQmlListProperty<Player>* list);

private:

    QString m_title;
    QString m_coatch;
    Player* m_captain;
    QList<Player*> m_players;

};