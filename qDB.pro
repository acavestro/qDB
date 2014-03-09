#-------------------------------------------------
#
# Project created by QtCreator 2014-03-05T08:57:01
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = qDB
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ContoBancario.cpp \
    ContoRisparmio.cpp \
    ContoCorrente.cpp \
    ElencoConti.cpp

HEADERS  += mainwindow.h \
    Container.h \
    ContoBancario.h \
    ContoRisparmio.h \
    ContoCorrente.h \
    ElencoConti.h

FORMS    += mainwindow.ui
