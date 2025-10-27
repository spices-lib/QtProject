#pragma once
#include "Player.h"

class Defender : public Player
{
    Q_OBJECT
    QML_ELEMENT

public:

    explicit Defender(QObject* parent = nullptr);

    void play() override;

    void defend();

};