/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/PictureComponent.h"
#include <QDebug>
#include <QStyleOptionGraphicsItem>

// void pdr::PictureComponent::paintEvent(QPaintEvent *event)
void pdr::PictureComponent::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *option,
                                  QWidget *widget)
{
    if (!effect)
    {
        switch (scale)
        {
            case Scale::IgnoreAspecRatio:
            {
                QImage *temp = image ;
                image = new QImage(image->scaled(800, 600, Qt::IgnoreAspectRatio));
                delete temp ;
                break ;
            }
            default:
                break ;
        }

        // painter->drawImage(0, 0, *image);

        qreal width = (image->width() > 800) ? 800 : image->width() ;
        qreal height = (image->height() > 600) ? 600 : image->height() ;
        // qDebug() << width << height ;
        // this->setPos(QPointF((800-width)/2, (600-height)/2));
        painter->drawImage((800-width)/2, (600-height)/2, *image);
    }
}

QRectF pdr::PictureComponent::boundingRect() const
{
    return QRectF(0,0,800,600) ;
}

void pdr::PictureComponent::play()
{
}

void pdr::PictureComponent::stop()
{
}



