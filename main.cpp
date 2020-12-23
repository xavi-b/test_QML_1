#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <ctime>
#include "sensor.h"
#include "sensormanager.h"

int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    SensorManager manager;
    manager.initTestSensors();
    manager.startFakeChanges();

    qmlRegisterType<Sensor>("Sensor", 1, 0, "Sensor");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("SensorManager", &manager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
