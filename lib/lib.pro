CONFIG -= QT

include(../RayTracer.pri)

TARGET = LibRayTracer
TEMPLATE = lib

OBJECTS_DIR = $$RAYTRACER_OBJ_LIB

CONFIG+= staticlib

SOURCES += \
    rendering/ray.cpp \
    rendering/primitive/iprimitive.cpp \
    rendering/primitive/sphere.cpp \
    math/types.cpp \
    rendering/scene.cpp \
    rendering/raytracer.cpp

HEADERS  += \ 
    rendering/ray.hpp \
    math/types.hpp \
    rendering/types.hpp \
    rendering/primitive/iprimitive.hpp \
    rendering/primitive/sphere.hpp \
    rendering/scene.hpp \
    rendering/raytracer.hpp
