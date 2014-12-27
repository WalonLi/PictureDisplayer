/**
    Provide by Walon Li, YJ Fang

    File Component.h
**/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include "../IPlay.h"

namespace pdr
{
class Component : public IPlay
{
public :
    explicit Component(QWidget *w) : IPlay(), base_widget(w){}
    ~Component(){}

    QWidget* getBaseWidget() { return base_widget ; }

    virtual void play(){}
    virtual void stop(){}
    virtual void forward(){}
    virtual void backward(){}
private :
    QWidget *base_widget ;
} ;
}
#endif
