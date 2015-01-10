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
#include "PlayPauseBtn.h"
#include "CloseBtn.h"

namespace pdr
{
class GraphicsView : public QGraphicsView
{

public :
    explicit GraphicsView(QWidget *parent=0) ;
    virtual ~GraphicsView() ;

    //void paintEvent(QPaintEvent*) ;
    //QSize sizeHint() const ;
    void mouseMoveEvent(QMouseEvent *e) ;
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QGraphicsScene *scene_ ;
    PlayPauseBtn *pp_btn_;
    CloseBtn *close_btn_;
} ;
}
#endif
