/**
    Provide by Walon Li, YJ Fang

    File main.cpp
**/

#include "include/SelectorWindow.h"
#include "include/PlayerWindow.h"
#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <chrono>

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

    // below code to make a parser
    controller->setBGMusic(QDir::currentPath().toStdString() + "/../music/bg_music.mp3");

    pdr::Frame *frame1 = new pdr::Frame(std::chrono::milliseconds(2000)) ;
    frame1->addComponent(new pdr::PictureComponent(new QImage("../image/walon.jpg"),
                                                  pdr::PictureComponent::IgnoreAspecRatio));

    pdr::Frame *frame2 = new pdr::Frame(std::chrono::milliseconds(2000)) ;
    frame2->addComponent(new pdr::PictureComponent(new QImage("../image/walon2.jpg")));

    controller->addFrame(frame1);
    controller->addFrame(frame2);



    PlayerWindow player_window;
    player_window.show();
    MoveToCenter(player_window) ;
    app.exec();


    return 0 ;
}
