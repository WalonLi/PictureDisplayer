/**
    Provide by Walon Li, YJ Fang

    File IPlay.h
**/

#ifndef IPLAY_H
#define IPLAY_H

namespace pdr
{
class IPlay 
{
public:
    IPlay(){}
    ~IPlay(){}
    virtual void play() = 0 ;
    virtual void stop() = 0 ;
    virtual void forward() = 0 ;
    virtual void backward() = 0 ;
} ;
}
#endif
