/**
    Provide by Walon Li, YJ Fang

    File NoneEffective.h
**/

#ifndef NONE_EFFECTIVE_H
#define NONE_EFFECTIVE_H

#include "Effective.h"

namespace pdr
{
class NoneEffective : public Effective
{
    explicit NoneEffective() : Effective() {}
    virtual ~NoneEffective(){}
    void play(){}
} ;
}
#endif
