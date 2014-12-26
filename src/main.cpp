/**
    Provide by Walon Li, YJ Fang

    File main.cpp
**/

#include "include/SelectorWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SelectorWindow w;
    w.show();

    return a.exec();
}
