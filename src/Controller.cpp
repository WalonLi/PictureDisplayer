/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QTest>

pdr::Controller::Controller()
    : IPlay(),
      frames(),
      threads(),
      bg_color(DEFAULT_BG_COLOR),
      bg_music_file(""),
      parent(0),
      view(0)
{
}

pdr::Controller::~Controller()
{
    while (this->frames.size()) {
        delete this->frames.back();
        this->frames.pop_back();
    }
    while (this->threads.size()) {
        this->threads.back()->interrupt() ;
        delete this->threads.back();
        this->threads.pop_back();
    }
}

void pdr::Controller::resetController()
{
    while (this->frames.size()) {
        delete this->frames.back();
        this->frames.pop_back();
    }
    while (this->threads.size()) {
        this->threads.back()->interrupt() ;
        delete this->threads.back();
        this->threads.pop_back();
    }
}

pdr::Controller * pdr::Controller::getInstance()
{
    static pdr::Controller instance;

    return &instance;
}

void pdr::Controller::addFrame(Frame *frame)
{
    this->frames.push_back(frame);
}

void pdr::Controller::play()
{
    qDebug() << "I'm playing" ;
    QGraphicsScene *scene = view->scene() ;
    view->setBackgroundBrush(bg_color);

    QTest::qWait(500) ; // wait few second to start play;

    /*
    view->graphicsView->setBackgroundBrush(QColor(0, 0xff, 0, 30));
    scene->addItem(new pdr::PictureComponent(scene,
                                             new QImage("../image/walon.jpg"),
                                             pdr::PictureComponent::IgnoreAspecRatio));
    */
    scene->addItem(new pdr::PictureComponent(scene, new QImage("../image/walon.jpg"))) ;
    scene->update();
}

void pdr::Controller::stop()
{
}
