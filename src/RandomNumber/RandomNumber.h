#pragma once
#include <QtQuick>
#include <QtQml>
#include <QQmlPropertyValueSource>

class RandomNumber : public QObject, public QQmlPropertyValueSource
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)
    Q_INTERFACES(QQmlPropertyValueSource)

public:

    explicit RandomNumber(QObject *parent = nullptr);
    virtual void setTarget(QQmlProperty const&) override;
    int maxValue() const { return m_maxValue; }
    void setMaxValue(int maxValue);

signals:

    void maxValueChanged();

private slots:

    void updateValue();

private:

    QTimer* m_timer;
    int m_maxValue;
    QQmlProperty m_property;
};



