#include "sensormanager.h"

SensorManager::SensorManager(QObject* parent) : QObject(parent)
{
    this->faker.setSingleShot(false);
    connect(&this->faker, &QTimer::timeout, this, [=](){
        for(auto& sensor : this->sensors)
        {
            sensor->setStrength(std::rand()%100);
            sensor->setState(static_cast<Sensor::State>(std::rand()%static_cast<int>(Sensor::State::__SIZE)));
        }
    });
}

void SensorManager::initTestSensors()
{
    this->sensors = {
        new Sensor(Sensor::GPS, "Front gps", this),
        new Sensor(Sensor::GPS, "Rear gps", this),
        new Sensor(Sensor::GPS, "Starboard gps", this),
        new Sensor(Sensor::GPS, "Port gps", this),
        new Sensor(Sensor::Compass, "Compass #1", this),
        new Sensor(Sensor::Compass, "Compass #2", this),
        new Sensor(Sensor::Compass, "Compass #3", this),
        new Sensor(Sensor::Compass, "Compass #4", this),
        new Sensor(Sensor::Anemometer, "Primary anemometer", this),
        new Sensor(Sensor::Anemometer, "Secondary anemometer", this),
        new Sensor(Sensor::Gyro, "Main gyro", this),
        new Sensor(Sensor::Gyro, "Backup gyro", this)
    };
    emit sensorsChanged(this->sensors);
}

void SensorManager::startFakeChanges()
{
    this->faker.start(1000);
}

QList<Sensor*> const& SensorManager::getSensors() const
{
    return this->sensors;
}
