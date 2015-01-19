/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.cpp
**/

#include "include/Effective/LinearMoveEffect.h"


pdr::LinearMoveEffect::LinearMoveEffect(QPointF p1, QPointF p2, boost::chrono::milliseconds m):
    Effective(),
    move_pos_(),
    start_pos_(p1),
    end_pos_(p2)
{
    // per 50 milisecond to refresh.
    m /= 50 ;
    progress_ = m.count() ;
    move_pos_= (p2-p1) / progress_;
}

pdr::LinearMoveEffect::~LinearMoveEffect()
{
}

void pdr::LinearMoveEffect::prepare(QGraphicsItem *item)
{
    item->moveBy(start_pos_.x(), start_pos_.y());
}

void pdr::LinearMoveEffect::play(QGraphicsItem *item)
{

    if (progress_)
    {
        item->moveBy(move_pos_.x(), move_pos_.y());
        progress_-- ;
    }
}
