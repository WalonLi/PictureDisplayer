#-------------------------------------------------
#
# Project created by QtCreator 2014-12-26T22:59:55
#
#-------------------------------------------------

QT       += core gui declarative testlib multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PictureDisplayer
TEMPLATE = app

## Enviroment Setting ##
linux-g++* {
    INCLUDEPATH += /usr/include/boost_1_57_0
    LIBS += -L/usr/lib/boost_lib -lboost_system -lboost_thread
}

win32-g++* {
    Boost_VERSION = 1_57
    COMPILER = mgw48
    Boost_DIR = G:/boost_1_57_0
    INCLUDEPATH += $${Boost_DIR}
    LIBS += $${Boost_DIR}/stage/lib/libboost_filesystem-$${COMPILER}-mt-$${Boost_VERSION}.a \
            $${Boost_DIR}/stage/lib/libboost_system-$${COMPILER}-mt-$${Boost_VERSION}.a \
            $${Boost_DIR}/stage/lib/libboost_thread-$${COMPILER}-mt-$${Boost_VERSION}.a \
            $${Boost_DIR}/stage/lib/libboost_chrono-$${COMPILER}-mt-$${Boost_VERSION}.a \
            -lws2_32
    QMAKE_CXXFLAGS += -mwindows
    QMAKE_LFLAGS += $$QMAKE_LFLAGS_WINDOWS
#    QMAKE_LFLAGS_CONSOLE =
}

CONFIG  +=  c++11 console
#DEFINES += STATIC

SOURCES +=  \
    src/main.cpp \
    src/SelectorWindow.cpp \
    src/Component/PictureComponent.cpp \
    src/PlayerWindow.cpp \
    src/Controller.cpp \
    src/PlayerLayout/PlayPauseBtn.cpp \
    src/PlayerLayout/GraphicsView.cpp \
    src/PlayerLayout/CloseBtn.cpp \
    src/Frame.cpp \
    src/Component/TextComponent.cpp \
    src/Component/SoundComponent.cpp \
    src/PlayerLayout/CycleBtn.cpp \
    src/PlayerLayout/LoadFileBtn.cpp \
    src/Effective/LinearMoveEffect.cpp \
    src/Effective/RectScrewInOutEffect.cpp


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
    include/Controller.h \
    include/PlayerLayout/PlayPauseBtn.h \
    include/PlayerLayout/GraphicsView.h \
    include/PlayerLayout/CloseBtn.h \
    include/PlayThread.h \
    include/Component/SoundComponent.h \
    include/PlayerLayout/CycleBtn.h \
    include/PlayerLayout/LoadFileBtn.h \
    include/Effective/LinearMoveEffect.h \
    include/Effective/RectScrewInOutEffect.h \
    include/PlayerLayout/AbstractPlayerButton.h

FORMS   +=  ui/Selector.ui\
            ui/Player.ui
 
