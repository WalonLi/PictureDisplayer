/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QTest>
//#include <QMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAudioOutput>

pdr::Controller::Controller()
    : IPlay(),
      frames_(),
      threads_(),
      bg_color_(DEFAULT_BG_COLOR),
      bg_music_file_(""),
      parent_(0),
      view_(0)
{
}

pdr::Controller::~Controller()
{
    while (this->frames_.size()) {
        delete this->frames_.back();
        this->frames_.pop_back();
    }
    while (this->threads_.size()) {
        this->threads_.back()->interrupt() ;
        delete this->threads_.back();
        this->threads_.pop_back();
    }
}

void pdr::Controller::resetController()
{
    while (this->frames_.size()) {
        delete this->frames_.back();
        this->frames_.pop_back();
    }
    while (this->threads_.size()) {
        this->threads_.back()->interrupt() ;
        delete this->threads_.back();
        this->threads_.pop_back();
    }
}

pdr::Controller * pdr::Controller::getInstance()
{
    static pdr::Controller instance;

    return &instance;
}

void pdr::Controller::addFrame(Frame *frame)
{
    this->frames_.push_back(frame);
}

void pdr::Controller::play()
{
    qDebug() << "I'm playing" ;
    QGraphicsScene *scene = view_->scene() ;
    view_->setBackgroundBrush(bg_color_);

    QTest::qWait(500) ; // wait few second to start play;

    /*
    view->graphicsView->setBackgroundBrush(QColor(0, 0xff, 0, 30));
    scene->addItem(new pdr::PictureComponent(scene,
                                             new QImage("../image/walon.jpg"),
                                             pdr::PictureComponent::IgnoreAspecRatio));
    */
    QGraphicsItem *pic = new pdr::PictureComponent(scene, new QImage("../image/walon.jpg")) ;
    scene->addItem(pic) ;
    scene->update();

    // Set bg_music
    bg_music_file_ = "/home/WalonLi/Project/PictureDisplayer//music/bg_music.mp3" ;
    QMediaPlayer bg_music_player ;
    QMediaContent bg_media(QUrl::fromLocalFile(bg_music_file_.c_str())) ;
    bg_music_player.setMedia(bg_media) ;
    bg_music_player.play(); // it will open thread to play music!!


    QTest::qWait(15000) ;

    // sample to clean picture
    scene->removeItem(pic);
    scene->update();
}

void pdr::Controller::stop()
{
}
