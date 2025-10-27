#pragma once
#include <QtQuick>
#include <QtQml>

class Player : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)

public:

    explicit Player(QObject* parent = nullptr);

    QString name() const { return m_name; }
    bool playing() const { return m_playing; }
    QString position() const { return m_position; }

    void setName(QString name);
    void setPlaying(bool playing);
    void setPosition(QString position);

public slots:

    virtual void play() = 0;

signals:

    void nameChanged();
    void playingChanged();
    void positionChanged();

private:

    QString m_name;
    bool m_playing;
    QString m_position;

};