/**
    Provide by Walon Li, YJ Fang

    File IPlay.h
**/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QThread>
#include "Frame.h"
#include "IPlay.h"

namespace pdr
{
class Controller : IPlay
{
public:
    Controller() : IPlay(){}

    void play(){}
    void stop(){}
    void forward(){}
    void backward(){}

private:
    std::vector<Frame> frames ;
    std::vector<QThread> thread_obj ;
}
}
#endif
