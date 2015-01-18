/**
    Provide by Walon Li, YJ Fang

    File main.cpp
**/

#include "include/SelectorWindow.h"
#include "include/PlayerWindow.h"
#include "include/Controller.h"
#include "include/PlayThread.h"
#include "include/Component/PictureComponent.h"
#include "include/Component/TextComponent.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QFont>
#include <QTextItem>
#include <boost/chrono.hpp>

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
    controller->setBGMusic(QDir::currentPath().toStdString() + "/music/bg_music.mp3");

    pdr::Frame *frame1 = new pdr::Frame(boost::chrono::milliseconds(5000)) ;
    frame1->addComponent(new pdr::PictureComponent(new QImage("image/walon.jpg"),
                                                  pdr::PictureComponent::IgnoreAspecRatio));
    QFont f ;
    f.setBold(true);
    f.setPixelSize(30);
    frame1->addComponent(new pdr::TextComponent(
                             new pdr::TextItem("Hello",QColor(0,0xff,0,0xff),f)));
    //frame1->addComponent(new pdr::TextComponent(
    //                         new pdr::TextItem("Hello")));
    //frame1->addComponent(new pdr::TextComponent(
    //                         new pdr::TextItem("Hello",QColor(0,0xff,0,0xff),f),
    //                         QPointF(50,50)));

    pdr::Frame *frame2 = new pdr::Frame(boost::chrono::milliseconds(5000)) ;
    frame2->addComponent(new pdr::PictureComponent(new QImage("image/walon2.jpg")));


    controller->addFrame(frame1);
    controller->addFrame(frame2);


    PlayerWindow player_window;
    pdr::PlayThread p_t ;
    p_t.start();
    player_window.show();
    MoveToCenter(player_window) ;
    app.exec();
    p_t.terminate();
    return 0 ;
}
