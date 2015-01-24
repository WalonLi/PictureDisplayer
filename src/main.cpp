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
#include "include/Component/SoundComponent.h"
#include "include/Effective/LinearMoveEffect.h"
#include "include/Effective/RectScrewInOutEffect.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QFont>
#include <QPointF>
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
    controller->setBGMusic("music/bg_music.mp3");
#if 1
    pdr::Frame *frame1 = new pdr::Frame(boost::chrono::milliseconds(5000)) ;

    // Image demo
    frame1->addComponent(new pdr::PictureComponent(
                             new QImage("image/walon.jpg"),
                             QPointF(),
                             new pdr::LinearMoveEffect(
                                 QPointF(800,0),
                                 QPointF(-800,0),
                                 boost::chrono::milliseconds(5000))));


    // Text demo
    QFont f ;
    f.setBold(true);
    f.setPixelSize(30);
    frame1->addComponent(new pdr::TextComponent(
                             new pdr::TextItem("Hello",QColor(0,0xff,0,0xff),f),
                             QPointF(),
                             new pdr::LinearMoveEffect(
                                 QPointF(800+366,540),
                                 QPointF(-800+366,540),
                                 boost::chrono::milliseconds(5000))));
    //frame1->addComponent(new pdr::TextComponent(
    //                         new pdr::TextItem("Hello")));
    //frame1->addComponent(new pdr::TextComponent(
    //                         new pdr::TextItem("Hello",QColor(0,0xff,0,0xff),f),
    //                         QPointF(50,50)));

    // sound demo
    //frame1->addComponent(new pdr::SoundComponent("music/oldcarhorn.wav"));
    frame1->addComponent(new pdr::SoundComponent("music/oldcarhorn.wav",
                                                 boost::chrono::milliseconds(2000)));


    pdr::Frame *frame2 = new pdr::Frame(boost::chrono::milliseconds(5000)) ;
    frame2->addComponent(new pdr::PictureComponent(new QImage("image/walon2.jpg")));

    controller->addFrame(frame1);
    controller->addFrame(frame2);
#endif

    pdr::Frame *frame3 = new pdr::Frame(boost::chrono::milliseconds(8000)) ;
    frame3->addComponent(new pdr::PictureComponent(new QImage("image/walon3.jpg"),
                                                   QPointF(),
                                                   new pdr::RectScrewInOutEffect(
                                                       boost::chrono::milliseconds(8000))));

    controller->addFrame(frame3);

    PlayerWindow player_window;
    pdr::PlayThread p_t ;
    player_window.show();
    MoveToCenter(player_window) ;
    p_t.start();
    app.exec();
    //p_t.terminate();
    //p_t.quit();
    p_t.wait() ;
    qDebug() <<"WHAT" ;
    return 0 ;
}
