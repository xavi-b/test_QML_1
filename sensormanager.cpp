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
        new Sensor(Sensor::GPS, "Front gps"),
        new Sensor(Sensor::GPS, "Rear gps"),
        new Sensor(Sensor::GPS, "Starboard gps"),
        new Sensor(Sensor::GPS, "Port gps"),
        new Sensor(Sensor::Compass, "Compass #1"),
        new Sensor(Sensor::Compass, "Compass #2"),
        new Sensor(Sensor::Compass, "Compass #3"),
        new Sensor(Sensor::Compass, "Compass #4"),
        new Sensor(Sensor::Anemometer, "Primary anemometer"),
        new Sensor(Sensor::Anemometer, "Secondary anemometer"),
        new Sensor(Sensor::Gyro, "Main gyro"),
        new Sensor(Sensor::Gyro, "Backup gyro")
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
