QT += core gui widgets

TARGET = RayTracer
TEMPLATE = app

include(../Raytracer.pri)

INCLUDEPATH += $$RAYTRACER_LIB

OBJECTS_DIR = $$RAYTRACER_OBJ_GUI
MOC_DIR = $$RAYTRACER_MOC_GUI

LIBS += -L$$RAYTRACER_BIN -lLibRayTracer

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp
