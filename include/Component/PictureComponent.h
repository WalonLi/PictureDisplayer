/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PICTURE_COMPONENT_H
#define PICTURE_COMPONENT_H

#include <QImage>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QTimerEvent>
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{
class PictureComponent : public Component
{
public :
    enum Scale
    {
        None = 0,
        IgnoreAspecRatio,
        KeepAspectRatio,
        KeepAspectRatioByExpanding,
    };


    explicit PictureComponent(QImage *i, Scale s = Scale::None, Effective *e = NULL) ;
    virtual ~PictureComponent() ;


    // PictureComponent.cpp implement it.
    void play() ;
    void pause() ;
    void resume() ;
    void stop() ;

    const QImage* getImage() const {return image_ ;}
    const Effective* getEffective() const {return effect_ ;}


    // override QGraphicsItem function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    void timerEvent(QTimerEvent*);
    QRectF boundingRect() const ;
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QImage *image_ ;
    Scale scale_;
    pdr::Effective *effect_ ;
} ;
}
#endif
