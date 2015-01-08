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
#include <chrono>
#include "../IPlay.h"

namespace pdr
{
class Component : public IPlay, public QGraphicsItem, public QObject
{
public :
    explicit Component(QObject *w) : IPlay(), QGraphicsItem(NULL), base_obj_(w), duration_(0){}
    virtual ~Component(){}

    QObject* getBaseObj() { return base_obj_ ; }
    void setDuration(std::chrono::milliseconds d){ duration_ = d;}
    std::chrono::milliseconds & getDuration() {return duration_ ;}

    virtual void play(){}
    virtual void stop(){}
    virtual void forward(){}
    virtual void backward(){}
private :
    QObject *base_obj_ ;
    std::chrono::milliseconds duration_ ;
} ;
}
#endif
