#include "keithley_2000.h"

const QMap<QString,DeviceParameterConstraint> Keithley_2000::deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READONLY)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2000::Keithley_2000(QString _interfaceName)
    : Keithley_2xxx(_interfaceName){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2000::getDeviceParameterConstraints()const{
    return deviceParamMap;
}

const QString Keithley_2000::getDeviceName()const{
    return deviceName;
}

const QString Keithley_2000::getInterfaceName()const{
    return interfaceName;
}

const QList<MeasurementValue> Keithley_2000::getMeasures(){

    // must redesign this function for asynchronous serial connection
    QList<MeasurementValue> measValList;
    for(int i = 0; i < ui->parameterTableWidget->rowCount(); i++){
        if (ui->parameterTableWidget->itemAt(0,i)->checkState()==Qt::Unchecked){
            continue;
        }
        QString valueName = ui->parameterTableWidget->itemAt(1,i)->text();
        // check if readable
        MeasurementValue value = getMeasure(valueName);
        measValList.append(value);
    }
}

MeasurementValue Keithley_2000::getMeasure(QString valueName){

}

void Keithley_2000::setScanParameter(MeasurementValue value){

}

void Keithley_2000::init(){
    MeasurementDevice::init(deviceName, interfaceName,deviceParamMap);
}

void Keithley_2000::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
}

void Keithley_2000::connectRS232(){
    MeasurementDevice::connectRS232(interfaceName, baudRate);
}
