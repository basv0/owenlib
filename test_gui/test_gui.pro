#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T08:13:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_gui
TEMPLATE = app


SOURCES += main.cpp\
        testowen.cpp

HEADERS  += testowen.h

FORMS    += testowen.ui

LIBS    += -lowen_io
