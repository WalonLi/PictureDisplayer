/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef BUTTON_EVENT_FILTER_H
#define BUTTON_EVENT_FILTER_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QEvent>
#include <QDebug>
#include <QAbstractButton>

namespace pdr
{
class ButtonEventFiler : public QObject
{
	Q_OBJECT
public :
    explicit ButtonEventFiler(QWidget *parent=0):
        QObject(parent){}

    bool eventFilter(QObject *object, QEvent *event)
    {
        /*
        switch(event->type())
        {
        case QEvent::MouseButtonDblClick:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        case QEvent::Paint:
        case QEvent::Timer:
            return false;
        default:
            return true;
        }
        */


        if(event->type() == QEvent::MouseMove
           || event->type() == QEvent::MouseTrackingChange) {

            qDebug() << "filter" ;
            return true ;
        }
        return false;
    }

} ;
}
#endif
