QT += core
QT -= gui

CONFIG += c++11

TARGET = ATEB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    logger/logger.cpp \
    pref_handler/preferencehandler.cpp \
    core/mainthread.cpp \
    core/messagingbroadcaster.cpp

HEADERS += \
    versions.h \
    logger/logger.h \
    pref_handler/preferencehandler.h \
    core/mainthread.h \
    core/messagingbroadcaster.h

DISTFILES += \
    config_template/main.conf \
    config_template/rs232.conf
