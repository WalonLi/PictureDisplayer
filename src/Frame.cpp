/**
    Provide by Walon Li, YJ Fang

    File Frame.cpp
**/

#include "include/Frame.h"
pdr::Frame::Frame(std::chrono::milliseconds d)
    : duration_(d)
{
}

pdr::Frame::~Frame()
{
    for (auto it = components_.begin() ; it != components_.end() ; ++it)
        delete *it ;
}
