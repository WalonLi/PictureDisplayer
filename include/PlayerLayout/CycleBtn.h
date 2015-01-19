/**
    Provide by Walon Li, YJ Fang

    File CycleBtn.h
**/

#ifndef CYCLE_BTN_H
#define CYCLE_BTN_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QAbstractButton>

namespace pdr
{
class CycleBtn : public QAbstractButton
{

public :
    explicit CycleBtn(QWidget *parent=0);
    virtual ~CycleBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void timerEvent(QTimerEvent *e) ;
private :
    QPixmap pixmap_ ;
    qreal progress_ ;
    // QIcon icon_ ;
} ;
}
#endif
