/**
    Provide by Walon Li, YJ Fang

    File LoadFileBtn.h
**/

#ifndef LOAD_FILE_BTN_H
#define LOAD_FILE_BTN_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QAbstractButton>

namespace pdr
{
class LoadFileBtn : public QAbstractButton
{

public :
    explicit LoadFileBtn(QWidget *parent=0);
    virtual ~LoadFileBtn(){}

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
