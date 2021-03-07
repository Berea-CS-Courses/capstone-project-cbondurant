TEMPLATE = app
TARGET = lipuma
DESTDIR = ../build/bin
OBJECTS_DIR = ../build/objects
MOC_DIR = ../build/moc
QT += gui widgets
unix:LIBS += -lFastNoise -ltcmalloc -lprofiler
SOURCES += main.cpp canvas.cpp fractalLine.cpp
HEADERS += canvas.hpp fractalLine.hpp pointhelper.hpp