#####################################################################
# cub.pro
#####################################################################

TEMPLATE = subdirs


PATHS *= \
     \
    ./objects \
    ./modules \
    ./object \

DEPENDPATH *= $$PATHS

include($$PWD/modules/timer/timer.pro)
include($$PWD/modules/graphics/graphics.pro)

include($$PWD/modules/main/main.pro)
