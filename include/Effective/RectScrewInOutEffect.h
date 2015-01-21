/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.h
**/

#ifndef RECT_SCREW_IN_OUT_EFFECT_H
#define RECT_SCREW_IN_OUT_EFFECT_H

#include <boost/chrono.hpp>
#include "Effective.h"

namespace pdr
{
using boost::chrono::milliseconds ;

class RectScrewInOutEffect : public Effective
{
public:
    explicit RectScrewInOutEffect(milliseconds m = milliseconds(1000));
    virtual ~RectScrewInOutEffect() ;

    void play(QGraphicsItem*, QPainter*);
    void play(QGraphicsItem*, QPainter*, QImage&) ;
    void play(QGraphicsItem*, QPainter*, QString&){}
    void prepare(QGraphicsItem* item) ;

    //const QPointF & getStartPos() const {return start_pos_;}
    //const QPointF & getEndPos() const {return end_pos_;}
private:
    QPointF move_pos_ ;
    QPointF start_pos_ ;
    QPointF end_pos_ ;
} ;
}
#endif
