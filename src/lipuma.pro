TEMPLATE = app
TARGET = lipuma
DESTDIR = ../build/bin
OBJECTS_DIR = ../build/objects
MOC_DIR = ../build/moc
INCLUDEPATH += .

# Currently I do not have a build system for windows
unix:LIBS += -lFastNoise -ltcmalloc -lprofiler
QT += gui widgets
CONFIG += debug

QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-enum-compare
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += main.cpp canvas.cpp fractalLine.cpp
HEADERS = canvas.hpp fractalLine.hpp pointhelper.hpp
