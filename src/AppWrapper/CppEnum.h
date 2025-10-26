#pragma once
#include <QObject>

class CppEnum
{
    Q_GADGET

public:

    CppEnum();

    enum ErrorValue{
        Error1,
        Error2,
        Error3
    };

    Q_ENUM(ErrorValue)

};