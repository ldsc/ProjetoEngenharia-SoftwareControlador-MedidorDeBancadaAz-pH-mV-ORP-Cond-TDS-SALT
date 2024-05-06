/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLCDNumber *lcd_value;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcd_temp;
    QLabel *label_130;
    QLabel *lb_mode;
    QLabel *label_134;
    QLabel *lb_unit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCustomPlot *gp_advanced_value;
    QCustomPlot *gp_advanced_temp;
    QWidget *tab_2;
    QCustomPlot *gp_analyzer_temp;
    QCustomPlot *gp_analyzer_value;
    QPushButton *btn_inspect;
    QPushButton *btn_inspect_2;
    QGroupBox *groupBox_6;
    QLabel *lb_record_date;
    QLabel *label_123;
    QLabel *lb_record_unit;
    QLabel *lb_record_mode;
    QLabel *label_12;
    QLabel *label_10;
    QGroupBox *groupBox_7;
    QLabel *label_124;
    QLabel *lb_record_value_dp;
    QLabel *label_125;
    QLabel *label_126;
    QLabel *lb_record_value_range;
    QLabel *lb_record_med_value;
    QGroupBox *groupBox_8;
    QLabel *label_129;
    QLabel *lb_record_temp_range;
    QLabel *label_127;
    QLabel *label_128;
    QLabel *lb_record_med_temp;
    QLabel *lb_record_temp_dp;
    QGroupBox *groupBox_9;
    QLabel *label_131;
    QLabel *lb_record_count;
    QLabel *lb_record_time;
    QLabel *label_132;
    QLabel *lb_record_refresh_rate;
    QLabel *label_133;
    QGroupBox *groupBox_2;
    QPushButton *btn_about;
    QPushButton *btn_calib;
    QPushButton *btn_rec;
    QPushButton *btn_hold;
    QGroupBox *gb_config;
    QSpinBox *sb_refresh_rate;
    QLabel *lb_refresh_rate;
    QLabel *label_7;
    QComboBox *cb_mode;
    QComboBox *cb_unit;
    QLabel *label_8;
    QComboBox *cb_sensor;
    QLabel *label_9;
    QDoubleSpinBox *ds_temp;
    QLabel *label_11;
    QCheckBox *chb_fixed_temp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 581, 131));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        lcd_value = new QLCDNumber(groupBox);
        lcd_value->setObjectName("lcd_value");
        lcd_value->setGeometry(QRect(20, 50, 151, 61));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 141, 31));
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 20, 141, 31));
        label_2->setFont(font);
        lcd_temp = new QLCDNumber(groupBox);
        lcd_temp->setObjectName("lcd_temp");
        lcd_temp->setGeometry(QRect(180, 50, 151, 61));
        label_130 = new QLabel(groupBox);
        label_130->setObjectName("label_130");
        label_130->setGeometry(QRect(350, 40, 221, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_130->setFont(font1);
        lb_mode = new QLabel(groupBox);
        lb_mode->setObjectName("lb_mode");
        lb_mode->setGeometry(QRect(350, 60, 221, 21));
        label_134 = new QLabel(groupBox);
        label_134->setObjectName("label_134");
        label_134->setGeometry(QRect(350, 80, 221, 21));
        label_134->setFont(font1);
        lb_unit = new QLabel(groupBox);
        lb_unit->setObjectName("lb_unit");
        lb_unit->setGeometry(QRect(350, 100, 221, 21));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 150, 901, 541));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        gp_advanced_value = new QCustomPlot(tab);
        gp_advanced_value->setObjectName("gp_advanced_value");
        gp_advanced_value->setGeometry(QRect(-1, -1, 901, 241));
        gp_advanced_temp = new QCustomPlot(tab);
        gp_advanced_temp->setObjectName("gp_advanced_temp");
        gp_advanced_temp->setGeometry(QRect(0, 240, 901, 270));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gp_analyzer_temp = new QCustomPlot(tab_2);
        gp_analyzer_temp->setObjectName("gp_analyzer_temp");
        gp_analyzer_temp->setGeometry(QRect(0, 330, 901, 181));
        gp_analyzer_value = new QCustomPlot(tab_2);
        gp_analyzer_value->setObjectName("gp_analyzer_value");
        gp_analyzer_value->setGeometry(QRect(0, 160, 901, 171));
        btn_inspect = new QPushButton(tab_2);
        btn_inspect->setObjectName("btn_inspect");
        btn_inspect->setGeometry(QRect(740, 10, 151, 71));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setStyleStrategy(QFont::PreferAntialias);
        btn_inspect->setFont(font2);
        btn_inspect_2 = new QPushButton(tab_2);
        btn_inspect_2->setObjectName("btn_inspect_2");
        btn_inspect_2->setGeometry(QRect(740, 90, 151, 71));
        btn_inspect_2->setFont(font2);
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 0, 180, 161));
        lb_record_date = new QLabel(groupBox_6);
        lb_record_date->setObjectName("lb_record_date");
        lb_record_date->setGeometry(QRect(10, 130, 161, 21));
        label_123 = new QLabel(groupBox_6);
        label_123->setObjectName("label_123");
        label_123->setGeometry(QRect(10, 30, 161, 21));
        label_123->setFont(font1);
        lb_record_unit = new QLabel(groupBox_6);
        lb_record_unit->setObjectName("lb_record_unit");
        lb_record_unit->setGeometry(QRect(10, 90, 181, 21));
        lb_record_mode = new QLabel(groupBox_6);
        lb_record_mode->setObjectName("lb_record_mode");
        lb_record_mode->setGeometry(QRect(10, 50, 161, 21));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 110, 161, 21));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_12->setFont(font3);
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 70, 161, 21));
        label_10->setFont(font3);
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(190, 0, 180, 161));
        label_124 = new QLabel(groupBox_7);
        label_124->setObjectName("label_124");
        label_124->setGeometry(QRect(10, 30, 151, 21));
        label_124->setFont(font1);
        lb_record_value_dp = new QLabel(groupBox_7);
        lb_record_value_dp->setObjectName("lb_record_value_dp");
        lb_record_value_dp->setGeometry(QRect(10, 90, 151, 21));
        label_125 = new QLabel(groupBox_7);
        label_125->setObjectName("label_125");
        label_125->setGeometry(QRect(10, 70, 171, 21));
        label_125->setFont(font1);
        label_126 = new QLabel(groupBox_7);
        label_126->setObjectName("label_126");
        label_126->setGeometry(QRect(10, 110, 151, 21));
        label_126->setFont(font1);
        lb_record_value_range = new QLabel(groupBox_7);
        lb_record_value_range->setObjectName("lb_record_value_range");
        lb_record_value_range->setGeometry(QRect(10, 50, 151, 21));
        lb_record_med_value = new QLabel(groupBox_7);
        lb_record_med_value->setObjectName("lb_record_med_value");
        lb_record_med_value->setGeometry(QRect(10, 130, 151, 21));
        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(370, 0, 180, 161));
        label_129 = new QLabel(groupBox_8);
        label_129->setObjectName("label_129");
        label_129->setGeometry(QRect(10, 30, 181, 21));
        label_129->setFont(font1);
        lb_record_temp_range = new QLabel(groupBox_8);
        lb_record_temp_range->setObjectName("lb_record_temp_range");
        lb_record_temp_range->setGeometry(QRect(10, 50, 181, 21));
        label_127 = new QLabel(groupBox_8);
        label_127->setObjectName("label_127");
        label_127->setGeometry(QRect(10, 70, 181, 21));
        label_127->setFont(font1);
        label_128 = new QLabel(groupBox_8);
        label_128->setObjectName("label_128");
        label_128->setGeometry(QRect(10, 110, 181, 21));
        label_128->setFont(font1);
        lb_record_med_temp = new QLabel(groupBox_8);
        lb_record_med_temp->setObjectName("lb_record_med_temp");
        lb_record_med_temp->setGeometry(QRect(10, 130, 181, 21));
        lb_record_temp_dp = new QLabel(groupBox_8);
        lb_record_temp_dp->setObjectName("lb_record_temp_dp");
        lb_record_temp_dp->setGeometry(QRect(10, 90, 181, 21));
        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(550, 0, 180, 161));
        label_131 = new QLabel(groupBox_9);
        label_131->setObjectName("label_131");
        label_131->setGeometry(QRect(10, 30, 171, 21));
        label_131->setFont(font1);
        lb_record_count = new QLabel(groupBox_9);
        lb_record_count->setObjectName("lb_record_count");
        lb_record_count->setGeometry(QRect(10, 50, 181, 21));
        lb_record_time = new QLabel(groupBox_9);
        lb_record_time->setObjectName("lb_record_time");
        lb_record_time->setGeometry(QRect(10, 90, 181, 21));
        label_132 = new QLabel(groupBox_9);
        label_132->setObjectName("label_132");
        label_132->setGeometry(QRect(10, 70, 181, 21));
        label_132->setFont(font1);
        lb_record_refresh_rate = new QLabel(groupBox_9);
        lb_record_refresh_rate->setObjectName("lb_record_refresh_rate");
        lb_record_refresh_rate->setGeometry(QRect(10, 130, 181, 21));
        label_133 = new QLabel(groupBox_9);
        label_133->setObjectName("label_133");
        label_133->setGeometry(QRect(10, 110, 181, 21));
        label_133->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(600, 10, 671, 131));
        groupBox_2->setFont(font);
        btn_about = new QPushButton(groupBox_2);
        btn_about->setObjectName("btn_about");
        btn_about->setGeometry(QRect(500, 40, 151, 61));
        btn_about->setFont(font2);
        btn_calib = new QPushButton(groupBox_2);
        btn_calib->setObjectName("btn_calib");
        btn_calib->setGeometry(QRect(340, 40, 151, 61));
        btn_calib->setFont(font2);
        btn_rec = new QPushButton(groupBox_2);
        btn_rec->setObjectName("btn_rec");
        btn_rec->setGeometry(QRect(180, 40, 151, 61));
        btn_rec->setFont(font2);
        btn_hold = new QPushButton(groupBox_2);
        btn_hold->setObjectName("btn_hold");
        btn_hold->setGeometry(QRect(20, 40, 151, 61));
        btn_hold->setFont(font2);
        gb_config = new QGroupBox(centralwidget);
        gb_config->setObjectName("gb_config");
        gb_config->setGeometry(QRect(920, 150, 341, 541));
        gb_config->setFont(font);
        sb_refresh_rate = new QSpinBox(gb_config);
        sb_refresh_rate->setObjectName("sb_refresh_rate");
        sb_refresh_rate->setGeometry(QRect(10, 60, 321, 31));
        sb_refresh_rate->setMinimum(1);
        sb_refresh_rate->setMaximum(999999);
        sb_refresh_rate->setValue(1000);
        lb_refresh_rate = new QLabel(gb_config);
        lb_refresh_rate->setObjectName("lb_refresh_rate");
        lb_refresh_rate->setGeometry(QRect(10, 30, 321, 31));
        lb_refresh_rate->setFont(font);
        label_7 = new QLabel(gb_config);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 170, 191, 31));
        label_7->setFont(font);
        cb_mode = new QComboBox(gb_config);
        cb_mode->setObjectName("cb_mode");
        cb_mode->setEnabled(false);
        cb_mode->setGeometry(QRect(8, 201, 321, 31));
        cb_unit = new QComboBox(gb_config);
        cb_unit->setObjectName("cb_unit");
        cb_unit->setEnabled(false);
        cb_unit->setGeometry(QRect(8, 271, 321, 31));
        label_8 = new QLabel(gb_config);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 191, 31));
        label_8->setFont(font);
        cb_sensor = new QComboBox(gb_config);
        cb_sensor->addItem(QString());
        cb_sensor->addItem(QString());
        cb_sensor->addItem(QString());
        cb_sensor->addItem(QString());
        cb_sensor->addItem(QString());
        cb_sensor->addItem(QString());
        cb_sensor->setObjectName("cb_sensor");
        cb_sensor->setGeometry(QRect(10, 130, 321, 31));
        label_9 = new QLabel(gb_config);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 100, 191, 31));
        label_9->setFont(font);
        ds_temp = new QDoubleSpinBox(gb_config);
        ds_temp->setObjectName("ds_temp");
        ds_temp->setEnabled(false);
        ds_temp->setGeometry(QRect(10, 340, 321, 31));
        label_11 = new QLabel(gb_config);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 310, 191, 31));
        label_11->setFont(font);
        chb_fixed_temp = new QCheckBox(gb_config);
        chb_fixed_temp->setObjectName("chb_fixed_temp");
        chb_fixed_temp->setGeometry(QRect(10, 380, 321, 20));
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
        label->setText(QCoreApplication::translate("MainWindow", "Sensor", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        label_130->setText(QCoreApplication::translate("MainWindow", "Modo de Funcionamento:", nullptr));
        lb_mode->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_134->setText(QCoreApplication::translate("MainWindow", "Unidade:", nullptr));
        lb_unit->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Monitor Avan\303\247ado", nullptr));
        btn_inspect->setText(QCoreApplication::translate("MainWindow", "Abir Grava\303\247\303\243o", nullptr));
        btn_inspect_2->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
        lb_record_date->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_123->setText(QCoreApplication::translate("MainWindow", "Modo:", nullptr));
        lb_record_unit->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        lb_record_mode->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Data & Hora:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Unidade de Medida:", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Medi\303\247\303\243o", nullptr));
        label_124->setText(QCoreApplication::translate("MainWindow", "Range (Min-Max):", nullptr));
        lb_record_value_dp->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_125->setText(QCoreApplication::translate("MainWindow", "Desvio Pad\303\243o (\317\203):", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "Mediana - M\303\251dia", nullptr));
        lb_record_value_range->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        lb_record_med_value->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        label_129->setText(QCoreApplication::translate("MainWindow", "Range (Min-Max):", nullptr));
        lb_record_temp_range->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_127->setText(QCoreApplication::translate("MainWindow", "Desvio Pad\303\243o (\317\203):", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "Mediana - M\303\251dia", nullptr));
        lb_record_med_temp->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        lb_record_temp_dp->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Grava\303\247\303\243o", nullptr));
        label_131->setText(QCoreApplication::translate("MainWindow", "Qtd de Registros:", nullptr));
        lb_record_count->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        lb_record_time->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_132->setText(QCoreApplication::translate("MainWindow", "Tempo Total (ms):", nullptr));
        lb_record_refresh_rate->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        label_133->setText(QCoreApplication::translate("MainWindow", "Taxa de Atualizacao:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Analyzer", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Controles", nullptr));
        btn_about->setText(QCoreApplication::translate("MainWindow", "Sobre \360\237\221\252", nullptr));
        btn_calib->setText(QCoreApplication::translate("MainWindow", "Calibrar", nullptr));
        btn_rec->setText(QCoreApplication::translate("MainWindow", "Gravar \360\237\224\264", nullptr));
        btn_hold->setText(QCoreApplication::translate("MainWindow", "Hold \342\234\213", nullptr));
        gb_config->setTitle(QCoreApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
        lb_refresh_rate->setText(QCoreApplication::translate("MainWindow", "Taxa de Atualizacao (ms)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Modo de Funcionamento", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Unidade de Medida", nullptr));
        cb_sensor->setItemText(0, QCoreApplication::translate("MainWindow", "[SELECIONE UM TIPO DE SENSOR]", nullptr));
        cb_sensor->setItemText(1, QCoreApplication::translate("MainWindow", "86501/551", nullptr));
        cb_sensor->setItemText(2, QCoreApplication::translate("MainWindow", "86502/552", nullptr));
        cb_sensor->setItemText(3, QCoreApplication::translate("MainWindow", "86503/553", nullptr));
        cb_sensor->setItemText(4, QCoreApplication::translate("MainWindow", "86504/554", nullptr));
        cb_sensor->setItemText(5, QCoreApplication::translate("MainWindow", "86505/555", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Tipo de Sensor", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        chb_fixed_temp->setText(QCoreApplication::translate("MainWindow", "Temperatura Fixa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
