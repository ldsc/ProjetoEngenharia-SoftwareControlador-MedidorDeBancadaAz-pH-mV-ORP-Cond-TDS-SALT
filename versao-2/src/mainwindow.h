#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enums.h"
#include "sensor.h"
#include "about.h"
#include <QMainWindow>

#include "Instrumentor.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Instrumentor;

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


private slots:
    void on_cb_mode_currentTextChanged(const QString &arg1);

    void on_cb_sensor_currentTextChanged(const QString &arg1);

    void on_sb_refresh_rate_valueChanged(int arg1);

    void on_btn_hold_clicked();

    void on_chb_fixed_temp_stateChanged(int arg1);

    void on_btn_about_clicked();

    void on_btn_rec_clicked();

    void on_cb_unit_currentTextChanged(const QString &arg1);

    void on_btn_inspect_clicked();

private:
    Ui::MainWindow *ui;
    int timerEventId;

protected:
    EMeasureMode measure_mode = EMeasureMode::EMeasureMode_Unknown;
    EMeasureUnit measure_unit = EMeasureUnit::EMeasureUnit_pH;
    ISensor* sensor = nullptr;
    void timerEvent(QTimerEvent *event);
    long timerEventCounter = 0;
    bool hold = false;
    bool rec = false;
    QList<IMeasure*>* record = nullptr;
};
#endif // MAINWINDOW_H
