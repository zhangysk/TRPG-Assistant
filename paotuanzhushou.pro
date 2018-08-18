#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T19:41:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paotuanzhushou
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


SOURCES += \
        main.cpp \
    mainwindow.cpp \
    tabwidget.cpp \
    editarea.cpp \
    treewidget.cpp \
    scene.cpp \
    npc.cpp \
    npceditor.cpp \
    infoeditor.cpp

HEADERS += \
    mainwindow.h \
    tabwidget.h \
    editarea.h \
    treewidget.h \
    scene.h \
    npc.h \
    npceditor.h \
    infoeditor.h

FORMS +=
