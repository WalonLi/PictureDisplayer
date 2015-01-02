/**
    Provide by Walon Li, YJ Fang

    File Component.h
**/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include <QDebug>
#include "../IPlay.h"

namespace pdr
{
class Component : public IPlay
{
public :
    explicit Component(QObject *w) : IPlay(), base_obj(w){}
    virtual ~Component(){}

    QObject* getBaseObj() { return base_obj ; }

    virtual void play(){}
    virtual void stop(){}
    virtual void forward(){}
    virtual void backward(){}
private :
    QObject *base_obj ;
} ;
}
#endif
