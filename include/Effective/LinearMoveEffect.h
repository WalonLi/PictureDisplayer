/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.h
**/

#ifndef RIGHT_MOVE_EFFECT_H
#define RIGHT_MOVE_EFFECT_H

#include <boost/chrono.hpp>
#include "Effective.h"

namespace pdr
{
using boost::chrono::milliseconds ;

class LinearMoveEffect : public Effective
{
public:
    explicit LinearMoveEffect(QPointF p1, QPointF p2, milliseconds m = milliseconds(1000)) ;
    virtual ~LinearMoveEffect() ;
    void play(QGraphicsItem*item) ;

    const QPointF & getStartPos() const {return start_pos_;}
    const QPointF & getEndPos() const {return end_pos_;}
private:
    QPointF move_pos_ ;
    QPointF start_pos_ ;
    QPointF end_pos_ ;
} ;
}
#endif
