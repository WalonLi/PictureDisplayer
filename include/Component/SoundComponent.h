/**
    Provide by Walon Li, YJ Fang

    File SoundComponent.h
**/

#ifndef SOUND_COMPONENT_H
#define SOUND_COMPONENT_H

#include <QPainter>
#include <QTimerEvent>
#include <QMediaPlayer>
#include <boost/chrono.hpp>
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{
using boost::chrono::milliseconds ;

class SoundComponent : public Component
{
public :
    SoundComponent(const std::string & a, milliseconds d = milliseconds(0)) ;
    SoundComponent(const QMediaContent & m, milliseconds d = milliseconds(0)) ;
    virtual ~SoundComponent() ;

    // SoundComponent.cpp implement it.
    void play() ;
    void pause() ;
    void resume() ;
    void stop() ;


    // override QGraphicsItem function
    void paint(QPainter *, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    void timerEvent(QTimerEvent*e);
    QRectF boundingRect() const ;
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QMediaPlayer sound_ ;
    milliseconds delay_ ;
    int progress_ ;
} ;
}
#endif
