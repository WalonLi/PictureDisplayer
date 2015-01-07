/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/PictureComponent.h"
#include <QDebug>
#include <QStyleOptionGraphicsItem>


pdr::PictureComponent::PictureComponent(QImage *i, Scale s, Effective *e):
    Component(NULL),
    image_(i),
    scale_(s),
    effect_(e)
{
    switch (scale_)
    {
        case Scale::IgnoreAspecRatio:
        {
            QImage *temp = image_ ;
            image_ = new QImage(image_->scaled(800, 600, Qt::IgnoreAspectRatio));
            delete temp ;
            break ;
        }
        default:
            break ;
    }
}

// void pdr::PictureComponent::paintEvent(QPaintEvent *event)
void pdr::PictureComponent::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *option,
                                  QWidget *widget)
{
    qreal width = (image_->width() > 800) ? 800 : image_->width() ;
    qreal height = (image_->height() > 600) ? 600 : image_->height() ;
    // qDebug() << width << height ;
    // this->setPos(QPointF((800-width)/2, (600-height)/2));
    // painter->drawImage(0, 0, *image);
    painter->drawImage((800-width)/2, (600-height)/2, *image_);
}

QRectF pdr::PictureComponent::boundingRect() const
{
    return QRectF(0,0,800,600) ;
}

void pdr::PictureComponent::play()
{
    //QTest::qWait(5000) ;
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)) ;
}

void pdr::PictureComponent::stop()
{
}



