#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T18:46:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RumIt
TEMPLATE = app


SOURCES += main.cpp\
        rumit.cpp \
    dialog.cpp \
    compress.cpp \
    decompress.cpp

HEADERS  += rumit.h \
    dialog.h \
    compress.h \
    decompress.h

FORMS    += rumit.ui \
    dialog.ui \
    compress.ui \
    decompress.ui

RESOURCES += \
    images.qrc
