#pragma once
#include <QObject>

class CppWorker : public QObject {

    Q_OBJECT

public:

    explicit CppWorker(QObject* parent = nullptr);

    // Q_INVOKABLE
    Q_INVOKABLE void regular_method();
    Q_INVOKABLE QString regular_method_with_return(QString name, int age);

public slots:

    void cppSlot();

};



