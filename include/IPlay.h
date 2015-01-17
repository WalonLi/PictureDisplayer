/**
    Provide by Walon Li, YJ Fang

    File IPlay.h
**/

#ifndef IPLAY_H
#define IPLAY_H

#include <QDebug>

namespace pdr
{
class IPlay 
{
public:
    IPlay(){}
    virtual ~IPlay(){}
    virtual void play() = 0 ;
    virtual void pause() = 0 ;
    virtual void resume() = 0 ;
    virtual void stop() = 0 ;
    virtual void forward() = 0 ;
    virtual void backward() = 0 ;
} ;
}
#endif
