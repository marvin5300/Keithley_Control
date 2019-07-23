#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "measurementdevice.h"
#include "serialconsole.h"
#include "filehandler.h"
#include <QMap>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void setOutputFile(QString filename);
    void nextInterval();
    void measure(quint64 count);
    void scanInit();
    void probeProgress(int progressStart = 0);

public slots:
    void onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);
    void onSettingsClicked();
    void onProgressReceived(int progress);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddAdjustValuesButtonClicked();
    void onAddMeasureValuesButtonClicked();
    void adjustProgressBarAppearance(int value);
    void onStartMeasurementButtonClicked();
    void finishedMeasurement();

private:
    Ui::MainWindow *ui;
    QPointer<FileHandler> fileHandler;
    QString highLevel = "QProgressBar {"
                        "background-color: #74c8ff;"
                        "color: #33ff33;"
                        "text-align: center; }"
                        "QProgressBar::chunk {"
                        "background-color: #010327; }";
    QString lowLevel =  "QProgressBar {"
                        "background-color: #74c8ff;"
                        "color: #008000;"
                        "text-align: center; }"
                        "QProgressBar::chunk {"
                        "background-color: #010327; }";
    bool ongoingMeasurement = false;
    void setUiMeasurementState(bool _ongoingMeasurement);
    void connectScanValues(bool doConnect);
    //QMap<QString, QPointer<MeasurementDevice> > loopDevices;
    //QMap<QString, DeviceParameterConstraint> loopParameters;
    //quint32 pendingScanParameters = 0;
    void onScanParameterReceived(MeasurementDevice *device, DeviceParameterConstraint constraint);
    //void measurementLoop();
    QTimer intervalTimer;
    quint64 measCount = 0;
};

#endif // MAINWINDOW_H
