#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>

class Sensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Type type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(State state READ getState WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(short strength READ getStrength WRITE setStrength NOTIFY strengthChanged)

public:
    enum Type : char
    {
        Anemometer,
        Compass,
        GPS,
        Gyro
    };
    Q_ENUM(Type)
    enum State : char
    {
        Nominal = 0,
        Warning,
        Error,
        __SIZE
    };
    Q_ENUM(State)

    explicit Sensor(QObject* parent = nullptr);
    explicit Sensor(Type, QString, QObject* parent = nullptr);

    Type getType() const;
    QString getName() const;
    State getState() const;
    char getStrength() const;

    void setType(Type);
    void setName(QString const&);
    void setState(State);
    void setStrength(short);

    Q_INVOKABLE QString typeName() const;

signals:
    void typeChanged(Type);
    void nameChanged(QString const&);
    void stateChanged(State);
    void strengthChanged(short);

private:
    Type type = Type::Anemometer;
    QString name = "Sensor";
    State state = State::Nominal;
    short strength = 0;
};

#endif // SENSOR_H
