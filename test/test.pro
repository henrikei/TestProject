TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_regex

SOURCES += main.cpp \
           operator/operator.cpp

HEADERS += \
           operator/operator.h

