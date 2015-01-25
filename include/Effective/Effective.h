/**
    Provide by Walon Li, YJ Fang

    File Effective.h
**/

#ifndef EFFECTIVE_H
#define EFFECTIVE_H

#include <QDebug>
#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>

namespace pdr
{
class Effective
{
public :
    explicit Effective() : progress_(0) {}
    virtual ~Effective(){}

    virtual void play(QGraphicsItem*) = 0 ;
    virtual void draw(QGraphicsItem*, QPainter*, const QImage&) = 0 ;
    virtual void draw(QGraphicsItem*, QPainter*, const std::string&) = 0 ;
    virtual void prepare(QGraphicsItem*) = 0 ;
protected :
    int progress_;
} ;
}
#endif
