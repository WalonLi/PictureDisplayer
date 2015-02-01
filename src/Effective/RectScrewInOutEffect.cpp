/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.cpp
**/

#include "include/Effective/RectScrewInOutEffect.h"
#include <QPainter>
#include <include/Component/Component.h>

pdr::RectScrewInOutEffect::RectScrewInOutEffect():
    Effective(),
    move_pos_(),
    comp_width_(0),
    comp_height_(0),
    before_progress_(0)
{
    // per 50 milisecond to refresh.
    // 800+600+800+300
    /*
    m /= 50 ;
    progress_ = m.count() ;
    move_pos_= (p2-p1) / progress_;
    */
    move_pos_ = QPointF(800,0) ;
}

pdr::RectScrewInOutEffect::~RectScrewInOutEffect()
{
}

void pdr::RectScrewInOutEffect::prepare(QGraphicsItem *item)
{
    if (Component *comp = dynamic_cast<Component*>(item))
    {
        comp_width_ = comp->compSize().width() ;
        comp_height_ = comp->compSize().height();
    }
    //item->moveBy(800,0);
    //item->matrix().rotate(5) ;
    //qDebug() <<item->mapRectToScene(item->boundingRect()) ;
    //qDebug() << item->boundingRect() ;
    //item->
}

void pdr::RectScrewInOutEffect::play(QGraphicsItem*)
{
    if (move_pos_.x() == 0 && progress_ == 0)
        progress_ = 1 ;
    else if (move_pos_.y()+comp_height_ == 600 && progress_ == 1)
        progress_ = 2 ;
    else if (move_pos_.x()+comp_width_ == 800 && progress_ == 2)
        progress_ = 3 ;
    else if (move_pos_.y() <= (600-comp_height_)/2 && progress_ == 3)
        progress_ = 4 ;
    else if (move_pos_.x() <= (800-comp_width_)/2 && progress_ == 4)
        progress_ = 5 ;

    if (before_progress_ != progress_)
    {
        // if status changed, skip this progress.
        before_progress_ = progress_;
        return ;
    }

    int temp = 0;
    switch (progress_)
    {
    case 0:
        move_pos_+= QPointF(-50, 0) ;
        break ;
    case 1:
        temp = 600-comp_height_-move_pos_.y() ;
        if (temp < 50)
            move_pos_+= QPointF(0, temp) ;
        else
            move_pos_+= QPointF(0, 50) ;
        break ;
    case 2:
        temp = 800-comp_width_-move_pos_.x() ;
        if (temp < 50)
            move_pos_+= QPointF(temp, 0) ;
        else
            move_pos_+= QPointF(50, 0) ;
        break ;
    case 3:
        temp = (600-comp_height_)/2 - move_pos_.y() ;
        if (temp > -50 )
            move_pos_+= QPointF(0, temp) ;
        else
            move_pos_+= QPointF(0, -50) ;
        break ;
    case 4:
        temp = (800-comp_width_)/2 - move_pos_.x() ;
        if (temp > -50 )
            move_pos_+= QPointF(temp, 0) ;
        else
            move_pos_+= QPointF(-50, 0) ;
        break ;
    default:

        break ;
    }
}

void pdr::RectScrewInOutEffect::draw(QGraphicsItem *, QPainter *painter, const QImage &image)
{
    painter->drawImage(move_pos_, image);
}












