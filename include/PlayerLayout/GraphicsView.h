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
#include <boost/thread.hpp>
#include "PlayPauseBtn.h"
#include "CloseBtn.h"
#include "CycleBtn.h"
#include "LoadFileBtn.h"

namespace pdr
{
class GraphicsView : public QGraphicsView
{

public :
    explicit GraphicsView(QWidget *parent=0) ;
    virtual ~GraphicsView() ;

    //void paintEvent(QPaintEvent*) ;
    //QSize sizeHint() const ;
    //void mouseMoveEvent(QMouseEvent *) ;
    void hideButton() ;
    void timerEvent(QTimerEvent *) ;

    PlayPauseBtn *getPlayPauseBtn() const {return pp_btn_ ;}
    CloseBtn *getCloseBtn() const {return close_btn_ ;}
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QGraphicsScene *scene_ ;
    CloseBtn *close_btn_;
    LoadFileBtn *load_file_btn_;
    CycleBtn *cycle_btn_;
    PlayPauseBtn *pp_btn_;
    boost::thread *hide_btn_thread_ ;
} ;
}
#endif
