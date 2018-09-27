#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T19:41:16
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paotuanzhushoushou
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
    summaryeditor.cpp \
    announcementeditor.cpp \
    mapeditor.cpp \
    map.cpp \
    script.cpp \
    scenepicshower.cpp \
    player.cpp \
    clickablelabel.cpp \
    normalnpceditor.cpp \
    keynpceditor.cpp \
    keynpc.cpp \
    normalnpc.cpp \
    battlescene.cpp \
    battlesceneeditor.cpp \
    normalscene.cpp \
    normalsceneeditor.cpp \
    filewidget.cpp \
    infowidget.cpp \
    npcwidget.cpp \
    scenewidget.cpp \
    border.cpp \
    multipledisplayer.cpp

HEADERS += \
    mainwindow.h \
    tabwidget.h \
    editarea.h \
    treewidget.h \
    summaryeditor.h \
    announcementeditor.h \
    mapeditor.h \
    map.h \
    script.h \
    scenepicshower.h \
    player.h \
    clickablelabel.h \
    normalnpceditor.h \
    keynpceditor.h \
    keynpc.h \
    normalnpc.h \
    battlescene.h \
    battlesceneeditor.h \
    normalscene.h \
    normalsceneeditor.h \
    filewidget.h \
    infowidget.h \
    npcwidget.h \
    scenewidget.h \
    border.h \
    multipledisplayer.h \
    data.h

FORMS +=

DISTFILES +=

RESOURCES += \
    rc.qrc
