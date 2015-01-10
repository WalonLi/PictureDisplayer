/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QScrollBar>
#include "include/PlayerLayout/GraphicsView.h"


pdr::GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    scene_(new QGraphicsScene()),
    pp_btn_(new PlayPauseBtn(this)),
    close_btn_(new CloseBtn(this))
{
    scene_->setSceneRect(0,0,800,600);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->verticalScrollBar()->blockSignals(true) ;
    this->horizontalScrollBar()->blockSignals(true) ;
    this->setScene(scene_);

    // button default is hidden
    pp_btn_->hide();
    close_btn_->hide();
}

void pdr::GraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    pp_btn_->show();
    close_btn_->show();
}

pdr::GraphicsView::~GraphicsView()
{
    delete scene_;
    delete pp_btn_ ;
    delete close_btn_ ;
}

/*
void pdr::PlayPauseBtn::paintEvent(QPaintEvent *e)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::PlayPauseBtn::sizeHint() const
{
    return pixmap_.size() ;
}
*/

