QT += core
QT -= gui

CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tratamatriz.cpp \
    tratalinha.cpp \
    tratacoluna.cpp \
    tratacubo.cpp \
    lermatriz.cpp

HEADERS += \
    tratamatriz.h \
    tratalinha.h \
    tratacoluna.h \
    tratacubo.h \
    lermatriz.h
