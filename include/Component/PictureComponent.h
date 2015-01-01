/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PICTURE_COMPONENT_H
#define PICTURE_COMPONENT_H

#include <QImage>
#include <QPainter>
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{
class PictureComponent : public Component, public QWidget
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
        QWidget(NULL),
        Component(base),
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

protected:
    // Override paint event.
    void paintEvent(QPaintEvent *event) ;

private :
    Effective *effect ;    
    QImage *image ;
    Scale scale;
} ;
}
#endif
