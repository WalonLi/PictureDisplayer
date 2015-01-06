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
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{
class PictureComponent : public Component, public QGraphicsItem
{
public :
    enum Scale
    {
        None = 0,
        IgnoreAspecRatio,
        KeepAspectRatio,
        KeepAspectRatioByExpanding,
    };


    explicit PictureComponent(QObject *base, QImage *i, Scale s = Scale::None, Effective *e = NULL) :
        Component(base),
        QGraphicsItem(NULL),
        image(i),
        scale(s),
        effect(e){}

    ~PictureComponent()
    {
        delete image ;
        delete effect ;
    }


    // PictureComponent.cpp implement it.
    void play() ;
    void stop() ;

    QImage* getImage() {return image ;}
    Effective* getEffective() {return effect ;}


    // override QGraphicsItem function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    QRectF boundingRect() const ;
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QImage *image ;
    Scale scale;
    pdr::Effective *effect ;
} ;
}
#endif
