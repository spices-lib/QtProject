#include "PropertyWrapper.h"
#include <stdlib.h>
#include <time.h>

PropertyWrapper::PropertyWrapper(QObject *parent)
    : QObject(parent)
    , m_lastname("LastName")
    , m_firstname("FirstName")
    , m_timer(new QTimer(this))
    , m_random_number(0)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    QStringList list;
    list << "Steward" << "Davis" << "Rodriguez" << "Martinez" << "Hernandez" << "Lopez" << "Gonzalez" << "Wilson" << "Anderson" << "Thomas" << "Taylor" << "Moore" << "Jackson" << "Martin" << "Lee" << "Perez" << "Thompson" << "White" << "Harris" << "Sanchez" << "Clark";

    connect(m_timer, &QTimer::timeout, [=]() {
        m_random_number = rand() % (list.size());
        setFirstname(list[m_random_number]);
    });
    m_timer->start(1000);
}

QString PropertyWrapper::lastname() const {
    return m_lastname;
}

QString PropertyWrapper::firstname() const {
    return m_firstname;
}

void PropertyWrapper::setLastname(const QString &lastname) {
    if (m_lastname == lastname)
        return;

    m_lastname = lastname;
    emit lastnameChanged(m_lastname);
}

void PropertyWrapper::setFirstname(const QString &firstname) {
    if (m_firstname == firstname)
        return;

    m_firstname = firstname;
    emit firstnameChanged(m_firstname);
}
