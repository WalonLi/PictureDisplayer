/**
    Provide by Walon Li, YJ Fang

    File Component.h
**/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsItem>
#include <thread>
#include <boost/chrono.hpp>
#include "../IPlay.h"

namespace pdr
{
class Component : public IPlay, public QGraphicsItem, public QObject
{
public :
    explicit Component(QObject *w) : IPlay(), QGraphicsItem(NULL), base_obj_(w), duration_(0){}
    virtual ~Component(){}

    const QObject* getBaseObj() const { return base_obj_ ; }

    void setDuration(const boost::chrono::milliseconds &d){ duration_ = d;}
    const boost::chrono::milliseconds & getDuration() const {return duration_ ;}

    virtual QSizeF compSize() const {return QSizeF(0,0);}

    virtual void play(){}
    virtual void pause(){}
    virtual void resume(){}
    virtual void stop(){}
    virtual void forward(){}
    virtual void backward(){}
private :
    QObject *base_obj_ ;
    boost::chrono::milliseconds duration_ ;
} ;
}
#endif
