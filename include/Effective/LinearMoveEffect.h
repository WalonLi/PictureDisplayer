/**
    Provide by Walon Li, YJ Fang

    File RightMoveEffect.h
**/

#ifndef LINEAR_MOVE_EFFECT_H
#define LINEAR_MOVE_EFFECT_H

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

    void play(QGraphicsItem*);
    void draw(QGraphicsItem*, QPainter*, const QImage&);
    void draw(QGraphicsItem*, QPainter*, const std::string&);
    void prepare(QGraphicsItem*);

    //const QPointF & getStartPos() const {return start_pos_;}
    //const QPointF & getEndPos() const {return end_pos_;}
private:
    QPointF move_pos_ ;
    QPointF start_pos_ ;
    QPointF end_pos_ ;
    int max_progress_ ;
} ;
}
#endif
