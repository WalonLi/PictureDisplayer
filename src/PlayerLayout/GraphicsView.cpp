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
    scene_(new QGraphicsScene()),
    pp_btn_(NULL),
    close_btn_(NULL),
    hide_btn_thread_(NULL)
{
    scene_->setSceneRect(0,0,800,600);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->verticalScrollBar()->blockSignals(true) ;
    this->horizontalScrollBar()->blockSignals(true) ;
    this->setScene(scene_);

    // button default is hidden
    // pp_btn_->hide();
    // close_btn_->hide();

    // this timer will check cursor move or not
    this->startTimer(500) ;

}

pdr::GraphicsView::~GraphicsView()
{
    if (hide_btn_thread_) hide_btn_thread_->interrupt();
    delete hide_btn_thread_ ;
    delete scene_;
    delete pp_btn_ ;
    delete close_btn_ ;
}

void pdr::GraphicsView::hideButton()
{
    volatile static u_int count ;
    count = 0 ;

    while (count < 30)
    {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100)) ;
        count++ ;
    }
    delete pp_btn_ ;
    delete close_btn_ ;
    pp_btn_ = NULL ;
    close_btn_ = NULL ;
}

void pdr::GraphicsView::timerEvent(QTimerEvent*)
{
    static QPoint org = QCursor::pos() ;
    QPoint mod = QCursor::pos() ;

    // check cursor in views or not
    if (!this->rect().contains(this->mapFromGlobal(mod)))
        return  ;

    if (mod != org)
    {
        org = mod ;

        if (!pp_btn_ || !close_btn_)
        {
            pp_btn_ = new PlayPauseBtn(this) ;
            close_btn_ = new CloseBtn(this) ;
            //pp_btn_->show();
            //close_btn_->show();
            this->scene()->update();
        }

        if (hide_btn_thread_)
        {
            hide_btn_thread_->interrupt();
            delete hide_btn_thread_ ;
        }
        hide_btn_thread_ = new boost::thread(&GraphicsView::hideButton, this) ;
    }
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
