QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_method_get_length.cpp


SOURCES += ../../set/Iterator.cpp \
        ../../set/set.cpp

HEADERS += ../../set/Iterator.h \
        ../../set/set.h
