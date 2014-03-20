#-------------------------------------------------
#
# Project created by QtCreator 2014-03-05T08:57:01
#
#-------------------------------------------------

QT       += core gui

TARGET = qDB
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ContoBancario.cpp \
    ContoRisparmio.cpp \
    ContoCorrente.cpp \
    ElencoConti.cpp \
    dialogaddaccount.cpp \
    dialogsearchaccount.cpp \
    dialogeditaccount.cpp

HEADERS  += mainwindow.h \
    Container.h \
    ContoBancario.h \
    ContoRisparmio.h \
    ContoCorrente.h \
    ElencoConti.h \
    dialogaddaccount.h \
    dialogsearchaccount.h \
    dialogeditaccount.h

FORMS    += mainwindow.ui \
    dialogaddaccount.ui \
    dialogsearchaccount.ui \
    dialogeditaccount.ui
