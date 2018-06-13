#-------------------------------------------------
#
# Project created by QtCreator 2018-04-13T08:39:44
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2018-4-13-final-Project
TEMPLATE = app
QT       += multimedia

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    plane.cpp \
    playerone.cpp \
    enemy.cpp \
    util_rand.cpp \
    bullet.cpp \
    boss.cpp \
    welcome_plane.cpp \
    mainwindow_dlgs.cpp

HEADERS += \
    plane.h \
    playerone.h \
    enemy.h \
    util_rand.h \
    bullet.h \
    boss.h \
    welcome_plane.h \
    mainwindow_dlgs.h

FORMS += \
    welcome_plane.ui \
    mainwindow_dlg.ui

RESOURCES += \
    res.qrc
