/**
    Provide by Walon Li, YJ Fang

    File Controller.h
**/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QThread>
#include <thread>
#include <QDebug>
#include "Frame.h"
#include "IPlay.h"

namespace pdr
{
class Controller : public IPlay
{
public:
    static pdr::Controller * getInstance();

    void addFrame(Frame *frame);

    template <typename Iterator>
    void addFrame(Iterator first, Iterator last);

    void play(){}
    void stop(){}
    void forward(){}
    void backward(){}

    void resetController() ;

private:
    Controller();
    ~Controller();

private:
    std::vector<Frame*> frames ;
    std::vector<std::thread*> threads ;
};
}

#include "include/Controller.tcc"

#endif
