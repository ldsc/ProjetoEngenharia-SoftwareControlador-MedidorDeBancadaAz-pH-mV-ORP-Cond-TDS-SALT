/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(400, 300);
        pushButton = new QPushButton(About);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 260, 381, 31));
        label = new QLabel(About);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 381, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 381, 20));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(About);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 381, 41));
        QFont font2;
        font2.setPointSize(10);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(About);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 190, 381, 20));
        QFont font3;
        font3.setPointSize(11);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(About);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 210, 381, 20));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(About);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(8, 160, 381, 20));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignCenter);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "About", nullptr));
        pushButton->setText(QCoreApplication::translate("About", "Close", nullptr));
        label->setText(QCoreApplication::translate("About", "PROJETO DE ENGENHARIA", nullptr));
        label_2->setText(QCoreApplication::translate("About", "DESENVOLVIMENTO DO SOFTWARE CONTROLADOR", nullptr));
        label_3->setText(QCoreApplication::translate("About", "Medidor de bancada Az \n"
" pH/mV/ORP/Cond./TDS/SALT", nullptr));
        label_4->setText(QCoreApplication::translate("About", "GUSTAVO ESCHER PIRES MENDES", nullptr));
        label_5->setText(QCoreApplication::translate("About", "PEDRO HENRIQUE AL JAWABRA RIBEIRO", nullptr));
        label_6->setText(QCoreApplication::translate("About", "Desenvolvido por", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
