/**
    Provide by Walon Li, YJ Fang

    File Controller.cpp
**/

#include "include/Controller.h"

pdr::Controller::Controller()
    : IPlay()
{

}

pdr::Controller::~Controller()
{
    while (this->frames.size()) {
        delete this->frames.back();

        this->frames.pop_back();
    }
    while (this->threads.size()) {
        delete this->threads.back();

        this->threads.pop_back();
    }
}

void pdr::Controller::resetController()
{
    while (this->frames.size()) {
        delete this->frames.back();

        this->frames.pop_back();
    }
    while (this->threads.size()) {
        delete this->threads.back();

        this->threads.pop_back();
    }
}

pdr::Controller * pdr::Controller::getInstance()
{
    static pdr::Controller instance;

    return &instance;
}

void pdr::Controller::addFrame(Frame *frame)
{
    this->frames.push_back(frame);
}
