/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef GRAPHICS_VIEW_H
#define GRAPHICS_VIEW_H

#include <QImage>
#include <QPainter>
#include <QGraphicsView>
#include <QRectF>

namespace pdr
{
class GraphicsView : public QGraphicsView
{

public :
    explicit GraphicsView(QWidget *parent=0) ;
    virtual ~GraphicsView() ;

protected:

private :
    QGraphicsScene *scene_ ;
} ;
}
#endif
