/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.cpp
**/

#include "include/Effective/RectScrewInOutEffect.h"
#include <QPainter>

pdr::RectScrewInOutEffect::RectScrewInOutEffect(boost::chrono::milliseconds m):
    Effective(),
    move_pos_(),
    start_pos_(),
    end_pos_()
{
    // per 50 milisecond to refresh.
    /*
    m /= 50 ;
    progress_ = m.count() ;
    move_pos_= (p2-p1) / progress_;
    */
}

pdr::RectScrewInOutEffect::~RectScrewInOutEffect()
{
}

void pdr::RectScrewInOutEffect::prepare(QGraphicsItem *item)
{
    //item->moveBy(800,0);
    //item->matrix().rotate(5) ;
    qDebug() <<item->mapRectToScene(item->boundingRect()) ;
    qDebug() << item->boundingRect() ;
    //item->
}

void pdr::RectScrewInOutEffect::play(QGraphicsItem *item)
{
    //p->draw
    //item->moveBy(-10, 0);
    static int c = 0 ;
    //p->drawImage(0, 50+c, i);
    c+=10 ;
    //p = new QPainter(item->se) ;
}

void pdr::RectScrewInOutEffect::draw(QGraphicsItem *item, QPainter *p, QImage & i)
{
    //p->draw
    //item->moveBy(-10, 0);
    static int c = 0 ;
    p->drawImage(0, 50+c, i);
    c+=10 ;
    //p = new QPainter(item->se) ;
}
