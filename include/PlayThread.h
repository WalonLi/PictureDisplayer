/**
    Provide by Walon Li, YJ Fang

    File PlayThread.h
**/

#ifndef PLAY_THREAD_H
#define PLAY_THREAD_H

#include <QThread>
#include "Controller.h"

namespace pdr
{
class PlayThread : public QThread
{
    Q_OBJECT
public:
    PlayThread(){}
    virtual ~PlayThread(){}

protected:
    void run()
    {
        Controller::getInstance()->play();
    }
};
}

#endif
