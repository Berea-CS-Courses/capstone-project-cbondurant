TEMPLATE = app
TARGET = lipuma
DESTDIR = ../build/bin
OBJECTS_DIR = ../build/objects
MOC_DIR = ../build/moc
QT += gui widgets
CONFIG += debug

unix:LIBS += -lFastNoise -ltcmalloc -lprofiler
SOURCES += main.cpp canvas.cpp fractalLine.cpp
SOURCES += tool/fractalTool.cpp tool/tool.cpp
HEADERS += canvas.hpp fractalLine.hpp pointhelper.hpp
HEADERS += tool/fractalTool.hpp tool/tool.hpp
