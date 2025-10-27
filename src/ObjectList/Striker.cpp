#include "Striker.h"

void Striker::play() {
    qDebug() << name() << "is playing" << position();
}

Striker::Striker(QObject *parent) : Player(parent) {

}

void Striker::strike() {
    qDebug() << name() << "is striking" << position();
}
