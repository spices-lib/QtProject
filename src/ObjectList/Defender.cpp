#include "Defender.h"

void Defender::play() {
    qDebug() << name() << "is playing" << position();
}

Defender::Defender(QObject *parent) : Player(parent) {

}

void Defender::defend() {
    qDebug() << name() << "is defending" << position();
}
