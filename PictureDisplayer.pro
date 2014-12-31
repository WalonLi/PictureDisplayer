#-------------------------------------------------
#
# Project created by QtCreator 2014-12-26T22:59:55
#
#-------------------------------------------------

QT       += core gui declarative testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PictureDisplayer
TEMPLATE = app

## Enviroment Setting ##
linux-g++* {
    INCLUDEPATH += /usr/include/boost_1_57_0
    LIBS += -L /usr/lib/boost_lib -lboost_system
}

win32-g++* {
    Boost_VERSION = 1_56
    COMPILER = mgw48
    Boost_DIR = G:/boost_1_56_0
    INCLUDEPATH += G:/boost_1_56_0
    LIBS += G:/boost_1_56_0/stage/lib/libboost_filesystem-$${COMPILER}-mt-$${Boost_VERSION}.a \
            G:/boost_1_56_0/stage/lib/libboost_system-$${COMPILER}-mt-$${Boost_VERSION}.a \
            -lws2_32
    PRE_TARGETDEPS += G:/boost_1_56_0/stage/lib/libboost_filesystem-$${COMPILER}-mt-$${Boost_VERSION}.a \
                      G:/boost_1_56_0/stage/lib/libboost_system-$${COMPILER}-mt-$${Boost_VERSION}.a
    QMAKE_CXXFLAGS += -mwindows
    QMAKE_LFLAGS += $$QMAKE_LFLAGS_WINDOWS
    QMAKE_LFLAGS_CONSOLE =
}

CONFIG  +=  c++11
#DEFINES += STATIC

SOURCES +=  \
    src/main.cpp \
    src/SelectorWindow.cpp \
    src/Component/PictureComponent.cpp \
    src/PlayerWindow.cpp \
    src/Controller.cpp

HEADERS +=  \
    include/SelectorWindow.h \
    include/IPlay.h \
    include/Component/Component.h \
    include/Component/PictureComponent.h \
    include/Component/TextComponent.h \
    include/Effective/Effective.h \
    include/Effective/NoneEffective.h \
    include/PlayerWindow.h \
    include/Frame.h \
    include/Controller.h

FORMS   +=  ui/Selector.ui\
            ui/Player.ui
 
