/**
    Provide by Walon Li, YJ Fang

    File TextComponent.h
**/

#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QTimerEvent>
#include <QTextItem>
#include "Component.h"
#include "../Effective/Effective.h"

namespace pdr
{

class TextItem
{
public:
    explicit TextItem(std::string s,
                      QColor c = QColor(Qt::GlobalColor::black),
                      QFont f = QFont()) :
                      str_(s), color_(c), font_(f){}
    virtual ~TextItem(){}

    /*
    void setString(const std::string &s) {str_ = s;}
    void setColor(const QColor &c) {color_ = c;}
    void setFont(const QFont &f) {font_ = f;}
    */

    const std::string & getString() const {return str_;}
    const QColor & getColor() const {return color_;}
    const QFont & getFont() const {return font_;}

private:
    std::string str_ ;
    QColor color_ ;
    QFont font_ ;
};


class TextComponent : public Component
{
public :
    explicit TextComponent(pdr::TextItem *t,
                           QPointF p = QPointF(),
                           Effective *e = NULL) ;
    virtual ~TextComponent() ;


    // TextComponent.cpp implement it.
    void play() ;
    void pause() ;
    void resume() ;
    void stop() ;

    const Effective* getEffective() const {return effect_ ;}


    // override QGraphicsItem function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    void timerEvent(QTimerEvent*);
    QRectF boundingRect() const ;
protected:

private :
    pdr::TextItem *item_ ;
    QRectF rect_ ;
    QPointF pos_ ;
    pdr::Effective *effect_ ;
} ;
}

#endif
