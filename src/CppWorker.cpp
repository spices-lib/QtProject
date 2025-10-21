#include "CppWorker.h"
#include <QDebug>
#include <iostream>

CppWorker::CppWorker(QObject *parent) : QObject(parent) {}

void CppWorker::regular_method() {
    qDebug() << "This is C++ talking, regularMethod called";
}

QString CppWorker::regular_method_with_return(QString name, int age) {
    const auto n = name.toStdString();
    qDebug() << "This is C++ talking, name: " << name << ", age" << age;
    return QString(name + ": " + QString::number(age) + " years old");
}

void CppWorker::cppSlot() {
    qDebug() << "This is C++ talking, cppSlot called";
}

void CppWorker::cppPrint(QString name) {
    std::cout << name.toStdString() << std::endl;
}


