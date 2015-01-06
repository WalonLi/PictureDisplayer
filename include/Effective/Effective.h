/**
    Provide by Walon Li, YJ Fang

    File Effective.h
**/

#ifndef EFFECTIVE_H
#define EFFECTIVE_H

#include <QWidget>
#include <QDebug>

namespace pdr
{
class Effective
{
public :
    explicit Effective(QWidget *w) : base_widget(w){}
    virtual ~Effective(){}

    QWidget* getBaseWidget() { return base_widget ; }

    virtual void pre() = 0 ;
    virtual void mid() = 0 ;
    virtual void post() = 0 ;
private :
    QWidget *base_widget ;
} ;
}
#endif
