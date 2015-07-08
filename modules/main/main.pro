#####################################################################
# main.pro
#####################################################################

TEMPLATE = app
TARGET = cub

QT =

OBJECTS_DIR = objects

SOURCES *= \
    $$PWD/src/main.cpp

HEADERS *= \
    $$PWD/include/types.h

PATHS *= \
    $$PWD           \
    $$PWD/src       \
    $$PWD/include

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS
