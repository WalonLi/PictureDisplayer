/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QScrollBar>
#include <boost/thread.hpp>
#include "include/PlayerLayout/GraphicsView.h"


pdr::GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    scene_(new QGraphicsScene())
{
    scene_->setSceneRect(0,0,800,600);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->verticalScrollBar()->blockSignals(true) ;
    this->horizontalScrollBar()->blockSignals(true) ;
    this->setScene(scene_);
}

pdr::GraphicsView::~GraphicsView()
{
    delete scene_;
}

#if 0
 **********BackUp Code**********
QMutex mutex1 ;
QMutex mutex2 ;
void pdr::GraphicsView::mouseMoveEvent(QMouseEvent *e)
{

}

    // QTimer::singleShot(1000,  new HideButtonTimer(hide_btn_timer_), SLOT(hideButtonSlot())) ;
    // hide_btn_thread_ = new boost::thread(&GraphicsView::WaitHide, this) ;
    QMutexLocker lock(&mutex1) ;

    e->t
    qDebug() << "111111" ;
    if (pp_btn_->isHidden() && close_btn_->isHidden())
    {
        pp_btn_->show();
        close_btn_->show();
        //boost::this_thread::sleep_for(boost::chrono::milliseconds(1000)) ;
        QTest::qSleep(1000) ;
        //std::this_thread::sleep_for(this->getDuration()) ;
    }
    qDebug() << "33333" ;

    {
        if (hide_btn_thread_)
        {
            hide_btn_thread_->interrupt();
            delete hide_btn_thread_ ;
        }
        hide_btn_thread_ = new boost::thread(&GraphicsView::WaitHide, this) ;
        // QTest::qWait(1000) ;
    }

#endif
