/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLCDNumber *lcd_Value;
    QLabel *lb_temperature;
    QLabel *lb_mode;
    QLabel *lb_unit;
    QLabel *lb_sensor_status;
    QTabWidget *tabWidget;
    QWidget *tab_dashboard;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QWidget *tab_recordings;
    QListView *listView;
    QWidget *tab_configuration;
    QGroupBox *groupBox_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_4;
    QLabel *label_7;
    QComboBox *comboBox_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_3;
    QPushButton *btn_hold;
    QPushButton *btn_rec;
    QPushButton *btn_calibrate;
    QPushButton *btn_about;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 601);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, -1, 521, 81));
        lcd_Value = new QLCDNumber(groupBox);
        lcd_Value->setObjectName("lcd_Value");
        lcd_Value->setGeometry(QRect(10, 20, 151, 51));
        lb_temperature = new QLabel(groupBox);
        lb_temperature->setObjectName("lb_temperature");
        lb_temperature->setGeometry(QRect(180, 20, 131, 20));
        lb_mode = new QLabel(groupBox);
        lb_mode->setObjectName("lb_mode");
        lb_mode->setGeometry(QRect(180, 50, 131, 20));
        lb_unit = new QLabel(groupBox);
        lb_unit->setObjectName("lb_unit");
        lb_unit->setGeometry(QRect(320, 50, 171, 20));
        lb_sensor_status = new QLabel(groupBox);
        lb_sensor_status->setObjectName("lb_sensor_status");
        lb_sensor_status->setGeometry(QRect(320, 20, 181, 21));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(6, 89, 981, 491));
        tab_dashboard = new QWidget();
        tab_dashboard->setObjectName("tab_dashboard");
        graphicsView = new QGraphicsView(tab_dashboard);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 951, 181));
        graphicsView_2 = new QGraphicsView(tab_dashboard);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(10, 240, 951, 181));
        tabWidget->addTab(tab_dashboard, QString());
        tab_recordings = new QWidget();
        tab_recordings->setObjectName("tab_recordings");
        listView = new QListView(tab_recordings);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(10, 10, 951, 441));
        tabWidget->addTab(tab_recordings, QString());
        tab_configuration = new QWidget();
        tab_configuration->setObjectName("tab_configuration");
        groupBox_2 = new QGroupBox(tab_configuration);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 951, 91));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 25, 81, 16));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 50, 191, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 25, 81, 16));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(210, 50, 191, 21));
        groupBox_4 = new QGroupBox(tab_configuration);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 110, 951, 91));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 25, 81, 16));
        comboBox_3 = new QComboBox(groupBox_4);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(10, 50, 191, 21));
        pushButton_5 = new QPushButton(tab_configuration);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(830, 410, 131, 41));
        pushButton_6 = new QPushButton(tab_configuration);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(690, 410, 131, 41));
        tabWidget->addTab(tab_configuration, QString());
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(539, -1, 451, 81));
        btn_hold = new QPushButton(groupBox_3);
        btn_hold->setObjectName("btn_hold");
        btn_hold->setGeometry(QRect(230, 20, 101, 51));
        btn_rec = new QPushButton(groupBox_3);
        btn_rec->setObjectName("btn_rec");
        btn_rec->setGeometry(QRect(10, 20, 101, 51));
        btn_calibrate = new QPushButton(groupBox_3);
        btn_calibrate->setObjectName("btn_calibrate");
        btn_calibrate->setGeometry(QRect(120, 20, 101, 51));
        btn_about = new QPushButton(groupBox_3);
        btn_about->setObjectName("btn_about");
        btn_about->setGeometry(QRect(340, 20, 101, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        lb_temperature->setText(QCoreApplication::translate("MainWindow", "\360\237\224\245 Temperature: 25 C", nullptr));
        lb_mode->setText(QCoreApplication::translate("MainWindow", "\360\237\244\235 Mode: pH Meter", nullptr));
        lb_unit->setText(QCoreApplication::translate("MainWindow", "\360\237\247\256 Unit: pH", nullptr));
        lb_sensor_status->setText(QCoreApplication::translate("MainWindow", "\360\237\224\214 Sensor status: Connected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_dashboard), QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_recordings), QCoreApplication::translate("MainWindow", "Recordings", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Geral", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Sensor", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sensor Type", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_configuration), QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Commands", nullptr));
        btn_hold->setText(QCoreApplication::translate("MainWindow", "Hold \342\234\213", nullptr));
        btn_rec->setText(QCoreApplication::translate("MainWindow", "REC \360\237\224\264", nullptr));
        btn_calibrate->setText(QCoreApplication::translate("MainWindow", "Calibrate \360\237\221\215", nullptr));
        btn_about->setText(QCoreApplication::translate("MainWindow", "About \360\237\221\250\342\200\215\360\237\222\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
