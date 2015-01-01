/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/PictureComponent.h"


void pdr::PictureComponent::paintEvent(QPaintEvent *event)
{
    // -5 ??????
    if (!effect)
    {
        switch (scale)
        {
            case Scale::IgnoreAspecRatio:
                QImage *temp = image ;
                image = new QImage(image->scaled(800-5, 600-5, Qt::IgnoreAspectRatio));
                delete temp ;
                break ;
            //default:
            //    break ;
        }

        QPainter paint(this) ;
        paint.drawImage(0,0, *image);
        int h = (image->height() > 800-5) ? 800-5 : image->height() ;
        int w = (image->width() > 600-5) ? 600-5 : image->width() ;
        this->resize(h, w);
    }
}

void pdr::PictureComponent::play()
{
}

void pdr::PictureComponent::stop()
{
}



