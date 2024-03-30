TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += node.h \
        Iterator.h \
        set.h

SOURCES += \
        main.cpp \
        Iterator.cpp \
        set.cpp
