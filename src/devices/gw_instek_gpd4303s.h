#ifndef GW_INSTEK_GPD4303S_H
#define GW_INSTEK_GPD4303S_H

#include <src/devices/scpidevice.h>

class GW_INSTEK_GPD4303S : public ScpiDevice
{
    Q_OBJECT

public:
    explicit GW_INSTEK_GPD4303S(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "GPD-4303S";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
    QString translateSet(QString paramName);
    QString translateMeas(QString paramName);
    bool outputState() {return outputON;}
    bool outputON = false;
};

#endif // GW_INSTEK_GPD4303S_H
