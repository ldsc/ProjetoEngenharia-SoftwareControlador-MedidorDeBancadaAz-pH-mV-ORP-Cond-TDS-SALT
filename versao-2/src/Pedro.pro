QT       += core widgets printsupport gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Instrumentor.cpp \
    about.cpp \
    main.cpp \
    mainwindow.cpp \
    measure.cpp \
    qcustomplot.cpp \
    sensor.cpp \
    utils.cpp

HEADERS += \
    Instrumentor.h \
    about.h \
    enums.h \
    mainwindow.h \
    measure.h \
    qcustomplot.h \
    sensor.h \
    utils.h

FORMS += \
    about.ui \
    mainwindow.ui

TRANSLATIONS += \
    Pedro_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations


