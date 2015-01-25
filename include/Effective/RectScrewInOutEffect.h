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
//using boost::chrono::milliseconds ;

class RectScrewInOutEffect : public Effective
{
public:
    explicit RectScrewInOutEffect();
    virtual ~RectScrewInOutEffect() ;

    void play(QGraphicsItem*);
    void draw(QGraphicsItem*, QPainter*, const QImage &) ;
    void draw(QGraphicsItem*, QPainter*, const std::string&){}
    void prepare(QGraphicsItem* item) ;

    //const QPointF & getStartPos() const {return start_pos_;}
    //const QPointF & getEndPos() const {return end_pos_;}
private:
    QPointF move_pos_ ;
    qreal comp_width_ ;
    qreal comp_height_;
    int before_progress_ ;
} ;
}
#endif
