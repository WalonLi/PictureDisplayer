/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QTest>
#include <QBitmap>
#include <boost/date_time.hpp>
//#include <QMultimedia>

pdr::Controller* pdr::Controller::instance = NULL ;

pdr::Controller::Controller()
    : IPlay(),
      frames_(),
      threads_(),
      bg_color_(DEFAULT_BG_COLOR),
      bg_music_player_(),
      state_(CTRL_STOP),
      view_(0),
      s_window_(0),
      p_window_(0)
{
}

pdr::Controller::~Controller()
{
    for (auto it = frames_.begin() ; it != frames_.end() ; ++it)
        delete *it ;

    /*
    while (this->frames_.size()) {
        delete this->frames_.back();
        this->frames_.pop_back();
    }
    while (this->threads_.size()) {
        this->threads_.back()->interrupt() ;
        delete this->threads_.back();
        this->threads_.pop_back();
    }
    */
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
    if (!instance) instance = new pdr::Controller() ;
    return instance ;
}

void pdr::Controller::freeInstance()
{
    if (instance) delete instance ;
    instance = NULL ;
}

void pdr::Controller::addFrame(Frame *frame)
{
    this->frames_.push_back(frame);
}

void pdr::Controller::play()
{
    qDebug() << "I'm playing" ;
    state_ = CTRL_PLAY ;

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
        std::chrono::milliseconds duration = (*it)->getDuration() ;
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
        {
            (*it2)->setDuration(duration) ;
            scene->addItem(*it2);
            scene->update();
            boost::thread *comp_t = new boost::thread(&Component::play, *it2) ;
            threads_.push_back(comp_t);
            (*it2)->update() ;
        }

        // wait for all thread
        for (auto it2 = threads_.begin() ; it2 != threads_.end() ; ++it2)
            (*it2)->join();

        // reset thread for next use
        this->resetThreads() ;

        // removes components
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
        {
            scene->removeItem(*it2);
            scene->update();
        }
    }

    bg_music_player_.stop();
    // once play is done, emit siganl to PlayerWindow(choose replay or another)
    if (p_window_) emit p_window_->playerEndSignal();
}

void pdr::Controller::pause_continue()
{

    if (state_ == CTRL_PLAY)
    {
        // pause
        boost::thread *t = threads_.at(0) ;
        //t->sleep(boost::posix_time::milliseconds(5000));
        bg_music_player_.pause();
        state_ = CTRL_PAUSE ;
    }
    else if (state_ == CTRL_PAUSE)
    {
        // continue
        bg_music_player_.play();
        state_ = CTRL_PLAY ;
    }
}

void pdr::Controller::stop()
{
    state_ = CTRL_STOP ;
}
