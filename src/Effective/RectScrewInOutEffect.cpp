/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.cpp
**/

#include "include/Effective/RectScrewInOutEffect.h"


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

}

void pdr::RectScrewInOutEffect::play(QGraphicsItem *item)
{
    if (progress_)
    {
        item->moveBy(move_pos_.x(), move_pos_.y());
        progress_-- ;
    }
}
