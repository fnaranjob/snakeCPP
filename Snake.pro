TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    snake.cpp \
    pixel.cpp

HEADERS += \
    board.h \
    snake.h \
    utils.h \
    pixel.h
