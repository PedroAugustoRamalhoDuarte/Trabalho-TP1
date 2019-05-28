#-------------------------------------------------
#
# Project created by QtCreator 2019-05-08T07:36:22
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

LIBS += -l sqlite3

SOURCES += \
        controladora.cpp \
        main.cpp \
        mainwindow.cpp \
        source/Entidades.cpp \
        source/Dominios.cpp \
        source/Model.cpp \
        source/View.cpp

HEADERS += \
        controladora.h \
        mainwindow.h \
        include/Entidades.h \
        include/Dominios.h \
        include/Model.h \
        include/View.h

FORMS += \
        controladora.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
