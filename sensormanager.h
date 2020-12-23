#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QObject>
#include <QTimer>
#include "sensor.h"

class SensorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Sensor*> sensors READ getSensors NOTIFY sensorsChanged)

public:
    explicit SensorManager(QObject* parent = nullptr);

    void initTestSensors();
    void startFakeChanges();

    const QList<Sensor*>& getSensors() const;

signals:
    void sensorsChanged(QList<Sensor*> const&);

private:
    QList<Sensor*> sensors;
    QTimer faker;
};

#endif // SENSORMANAGER_H
