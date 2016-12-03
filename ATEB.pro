QT += core
QT -= gui

CONFIG += c++11

TARGET = ATEB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    logger/logger.cpp \
    pref_handler/preferencehandler.cpp

HEADERS += \
    versions.h \
    logger/logger.h \
    pref_handler/preferencehandler.h
