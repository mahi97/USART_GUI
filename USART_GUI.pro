#-------------------------------------------------
#
# Project created by QtCreator 2019-01-13T21:46:43
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = USART_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controltab.cpp \
    infotab.cpp \
    configtab.cpp \
    serialwriter.cpp \
    serialreader.cpp \
    baseserial.cpp

HEADERS  += mainwindow.h \
    controltab.h \
    infotab.h \
    configtab.h \
    serialwriter.h \
    serialreader.h \
    baseserial.h

FORMS    +=
