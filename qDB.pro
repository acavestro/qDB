#-------------------------------------------------
#
# Project created by QtCreator 2014-03-05T08:57:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ContoBancario.cpp \
    ContoRisparmio.cpp \
    ContoCorrente.cpp \
    CBPointer.cpp

HEADERS  += mainwindow.h \
    Container.h \
    ContoBancario.h \
    ContoRisparmio.h \
    ContoCorrente.h \
    CBPpointer.h

FORMS    += mainwindow.ui
