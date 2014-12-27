/**
    Provide by Walon Li, YJ Fang

    File main.cpp
**/

#include "include/SelectorWindow.h"
#include "include/PlayerWindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SelectorWindow w;
    w.show();
    a.exec();
    PlayerWindow p;
    p.show();
    a.exec();
    return 0 ;
}
