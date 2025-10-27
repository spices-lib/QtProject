#pragma once
#include "Player.h"

class Striker : public Player
{
    Q_OBJECT
    QML_ELEMENT

public:

    explicit Striker(QObject* parent = nullptr);

    void play() override;

    void strike();

};