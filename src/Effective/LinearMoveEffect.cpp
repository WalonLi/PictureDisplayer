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
    max_progress_ = m.count() ;
    move_pos_= (p2-p1) / max_progress_;
    qDebug() << move_pos_;
}

pdr::LinearMoveEffect::~LinearMoveEffect()
{
}

void pdr::LinearMoveEffect::prepare(QGraphicsItem *)
{
    //item->moveBy(start_pos_.x(), start_pos_.y());
}

void pdr::LinearMoveEffect::play(QGraphicsItem*)
{
    if (max_progress_ > progress_)
    {
        progress_++ ;
    }
}

void pdr::LinearMoveEffect::draw(QGraphicsItem *, QPainter *painter, QImage &image)
{
    painter->drawImage(start_pos_+(progress_*move_pos_), image);
}

void pdr::LinearMoveEffect::draw(QGraphicsItem *, QPainter *painter, QString str)
{
    //qDebug() << "text" ;
    //painter->drawText(366,540,str);

    painter->drawText(start_pos_+(progress_*move_pos_), str);
}
