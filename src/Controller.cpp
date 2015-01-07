/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QTest>
//#include <QMultimedia>


pdr::Controller::Controller()
    : IPlay(),
      frames_(),
      threads_(),
      bg_color_(DEFAULT_BG_COLOR),
      bg_music_player_(),
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

void pdr::Controller::resetFrames()
{
    while (this->frames_.size()) {
        delete this->frames_.back();
        this->frames_.pop_back();
    }
}

void pdr::Controller::resetThreads()
{
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

    // Set background color
    view_->setBackgroundBrush(bg_color_);
    QGraphicsScene *scene = view_->scene() ;

    QTest::qWait(500) ; // wait few second to start play;

    // play background music
    bg_music_player_.play(); // it will open thread to play music!!

    qDebug() << "frameCount:" << frames_.size() ;
    for (auto it = frames_.begin() ; it != frames_.end() ; ++it)
    {
        // add component to scene and make its thread
        std::vector<Component*> comps = (*it)->getComponents() ;
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
        {
            scene->addItem(*it2);
            scene->update();
            boost::thread *comp_t = new boost::thread(&Component::play, *it2) ;
            threads_.push_back(comp_t);
            (*it2)->update() ;
        }


        // wait for all thread
        for (auto it2 = threads_.begin() ; it2 != threads_.end() ; ++it2)
        {
            (*it2)->join();
        }

        // reset thread for next use
        this->resetThreads() ;

        // removes components
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
        {
            scene->removeItem(*it2);
            scene->update();
        }
    }

    // once play is done, emit siganl to PlayerWindow(choose replay or another)
    // emit XXXX
}

void pdr::Controller::stop()
{
}
