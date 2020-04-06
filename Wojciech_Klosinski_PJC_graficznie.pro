#-------------------------------------------------
#
# Project created by QtCreator 2020-03-28T14:09:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wojciech_Klosinski_PJC_graficznie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    magik.cpp \
    agresor.cpp \
    hazardzista.cpp \
    skiller.cpp \
    pacyfista.cpp

HEADERS  += mainwindow.h \
    magik.h \
    agresor.h \
    hazardzista.h \
    skiller.h \
    pacyfista.h

FORMS    += mainwindow.ui

RESOURCES += \
    obrazy.qrc
