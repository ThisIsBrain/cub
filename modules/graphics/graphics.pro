#####################################################################
# graphics.pro
#####################################################################

TARGET = graphics

QT =

OBJECTS_DIR = objects

SOURCES *= \
    $$PWD/src/graphics_scene.cpp \
    $$PWD/src/texture.cpp \
    $$PWD/src/graphics_item.cpp \
    $$PWD/src/graphics_item_animation.cpp

HEADERS *= \
    $$PWD/include/graphics_scene.h \
    $$PWD/include/texture.h \
    $$PWD/include/graphics_item.h \
    $$PWD/include/graphics_item_animation.h

PATHS *= \
    $$PWD \
    $$PWD/src \
    $$PWD/include

LIBS    += -lSDL2 -lSDL2_image

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS
