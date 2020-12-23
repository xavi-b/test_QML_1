#include "sensor.h"

#include <QMetaEnum>

Sensor::Sensor(QObject* parent) : QObject(parent)
{
}

Sensor::Sensor(Type type, QString name, QObject* parent)
    : QObject(parent), type(type), name(name)
{
}

Sensor::Type Sensor::getType() const
{
    return type;
}

QString Sensor::getName() const
{
    return name;
}

Sensor::State Sensor::getState() const
{
    return state;
}

char Sensor::getStrength() const
{
    return strength;
}

void Sensor::setType(Type type)
{
    this->type = type;
    emit typeChanged(type);
}

void Sensor::setName(QString const& name)
{
    this->name = name;
    emit nameChanged(name);
}

void Sensor::setState(State state)
{
    this->state = state;
    emit stateChanged(state);
}

void Sensor::setStrength(short strength)
{
    strength       = std::max(0, std::min(100, (int)strength));
    this->strength = strength;
    emit strengthChanged(strength);
}

QString Sensor::typeName() const
{
    return QMetaEnum::fromType<Type>().valueToKey(this->type);
}
