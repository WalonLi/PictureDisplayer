/**
    Provide by Walon Li, YJ Fang

    File SoundComponent.cpp
**/

#include "include/Component/SoundComponent.h"
#include <QDebug>
#include <boost/thread.hpp>
#include <QThread>
#include <QDir>
#include <boost/format.hpp>


pdr::SoundComponent::SoundComponent(const std::string &a, boost::chrono::milliseconds d):
    Component(NULL),
    sound_(),
    delay_(d),
    progress_(0)
{
    std::string path = (boost::format("%s/%s")
                        % QDir::currentPath().toStdString()
                        % a).str() ;
    sound_.setMedia(QMediaContent(QUrl::fromLocalFile(path.c_str())));
}

pdr::SoundComponent::SoundComponent(const QMediaContent & m, boost::chrono::milliseconds d):
    Component(NULL),
    sound_(),
    delay_(d),
    progress_(0)
{
    sound_.setMedia(m);
}

pdr::SoundComponent::~SoundComponent()
{
}

void pdr::SoundComponent::timerEvent(QTimerEvent *e)
{
    if (delay_.count() == progress_)
    {
        sound_.play();
        this->killTimer(e->timerId());
    }
    if (!pause_flag_)
        progress_++;
}

void pdr::SoundComponent::paint(QPainter *,
                                const QStyleOptionGraphicsItem *,
                                QWidget *)
{
}

QRectF pdr::SoundComponent::boundingRect() const
{
    return QRectF(0,0,0,0) ;
}

void pdr::SoundComponent::play()
{
    delay_ /= 100 ;
    if (delay_.count())
        this->startTimer(100) ;
    else
        sound_.play();
}

void pdr::SoundComponent::pause()
{
    pause_flag_ = true ;
    if (sound_.state() == QMediaPlayer::PlayingState)
        sound_.pause();
}

void pdr::SoundComponent::resume()
{
    pause_flag_ = false ;
    if (sound_.state() == QMediaPlayer::PausedState)
        sound_.play();
}

void pdr::SoundComponent::stop()
{
    sound_.stop();
}



