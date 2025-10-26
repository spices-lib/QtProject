#include <QQmlTypeNotAvailable>
#include "CppEnum.h"

static CppEnum s_cppEnum;

CppEnum::CppEnum() {
    qmlRegisterUncreatableMetaObject(CppEnum::staticMetaObject, "CppEnum.ErrorValue", 1, 0, "ErrorValue", "CppEnum is an enum");
}
