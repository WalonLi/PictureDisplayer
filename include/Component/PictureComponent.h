/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PICTURE_COMPONENT_H
#define PICTURE_COMPONENT_H

#include <QImage>
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{
class PictureComponent : Component
{
public :
    explicit PictureComponent(QWidget *w, QImage *i, Effective *e = NULL) :
        Component(w), 
        image(i),
        effect(e){}

    ~PictureComponent(){}

    // PictureComponent.cpp implement it.
    void play() ;
    void stop() ;

private :
    Effective *effect ;    
    QImage *image ;
} ;
}
#endif
