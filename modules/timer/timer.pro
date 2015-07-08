#####################################################################
# timer.pro
#####################################################################

TARGET = timer

QT =

OBJECTS_DIR = objects

SOURCES *= \
    $$PWD/src/timer.cpp

HEADERS *= \
    $$PWD/include/timer.h

PATHS *= \
    $$PWD \
    $$PWD/src \
    $$PWD/include

LIBS    += -lSDL2 -lSDL2_image

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS
