/**
    Provide by Walon Li, YJ Fang

    File main.cpp
**/

#include "include/SelectorWindow.h"
#include "include/PlayerWindow.h"
#include "include/Controller.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

void MoveToCenter(QMainWindow& w)
{
    // move window to center.
    if (QApplication::desktop()->screenCount() <= 1)
    {
        w.move((QApplication::desktop()->width() - w.width())/2,
                (QApplication::desktop()->height() - w.height())/2);
    }
    else
    {
        QRect rect = QApplication::desktop()->screenGeometry(0);
        w.move((rect.width()-w.width())/2,
                (rect.height()-w.height())/2);
    }
}

int main(int argc, char *argv[])
{
    pdr::Controller *controller = pdr::Controller::getInstance();

    QApplication app(argc, argv);
    /*
    SelectorWindow select_window;
    select_window.show();
    MoveToCenter(select_window) ;
    app.exec();
    */

    PlayerWindow player_window;
    boost::thread m_t(&pdr::Controller::play, controller) ;
    player_window.show();
    MoveToCenter(player_window) ;
    app.exec();


    return 0 ;
}
