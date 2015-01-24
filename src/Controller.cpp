/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"
#include "include/Component/PictureComponent.h"
#include <QTest>
#include <QBitmap>
#include <boost/chrono.hpp>
//#include <QMultimedia>

pdr::Controller::Controller()
    : QObject(),
      IPlay(),
      frames_(),
      bg_color_(QColor(0, 0xff, 0, 30)),
      bg_music_player_(),
      state_(CTRL_STOP),
      view_(0),
      s_window_(0),
      p_window_(0)
{
}

pdr::Controller::~Controller()
{
    this->resetFrames() ;
}

void pdr::Controller::resetFrames()
{
    while (this->frames_.size()) {
        delete this->frames_.back();
        this->frames_.pop_back();
    }
}

pdr::Controller * pdr::Controller::getInstance()
{
    static pdr::Controller instance ;

    return &instance ;
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

    //QTest::qWait(500) ; // wait few second to start play;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(500)) ;

    // play background music
    bg_music_player_.play(); // it will open thread to play music!!

    qDebug() << "frameCount:" << frames_.size() ;
    for (auto it = frames_.begin() ; it != frames_.end() ; ++it)
    {
        // add component to scene and make its thread
        std::vector<Component*> comps = (*it)->getComponents() ;
        boost::chrono::milliseconds duration = (*it)->getDuration() ;
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
        {
            (*it2)->setDuration(duration) ;
            emit this->playCompSignals(*it2);
        }

        // start to play...
        duration /= 50 ;
        int count = 0 ;

        while (count < duration.count())
        {
            if (!pause_flag_)
            {
                boost::this_thread::sleep_for(boost::chrono::milliseconds(50)) ;
                //QTest::qWait(50);
                count++ ;
            }
            if (state_ == CTRL_STOP)
                return ;
        }

        // removes components
        for (auto it2 = comps.begin() ; it2 != comps.end() ; ++it2)
            emit this->stopCompSignals(*it2);
    }

    bg_music_player_.stop();
    // once play is done, emit siganl to PlayerWindow(choose replay or another)
    //if (p_window_) emit p_window_->endPlaySignals();
    emit this->endPlaySignals();
}

void pdr::Controller::pause()
{
    QList<QGraphicsItem*> lst = view_->scene()->items() ;
    for (auto it = lst.begin() ; it != lst.end() ; ++it)
        if (Component* comp = dynamic_cast<Component*>(*it))
            emit this->pauseCompSignals(comp);

    bg_music_player_.pause();
    pause_flag_ = true ;
    state_ = CTRL_PAUSE ;
}

void pdr::Controller::resume()
{
    QList<QGraphicsItem*> lst = view_->scene()->items() ;
    for (auto it = lst.begin() ; it != lst.end() ; ++it)
        if (Component* comp = dynamic_cast<Component*>(*it))
            emit this->resumeCompSignals(comp);
    bg_music_player_.play() ;
    pause_flag_ = false ;
    state_ = CTRL_PLAY ;
}

void pdr::Controller::stop()
{
    state_ = CTRL_STOP ;
    QList<QGraphicsItem*> lst = view_->scene()->items() ;
    for (auto it = lst.begin() ; it != lst.end() ; ++it)
        if (Component* comp = dynamic_cast<Component*>(*it))
        {
            emit this->stopCompSignals(comp);
        }
}
