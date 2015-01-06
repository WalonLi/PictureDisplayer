/**
    Provide by Walon Li, YJ Fang

    File IPlay.h
**/

#include <chrono>
#include <vector>
#include <QDebug>
#include "Component/Component.h"

namespace pdr
{
class Frame
{
public:
    explicit Frame(std::chrono::milliseconds d) : duration_(d) {}
    ~Frame()
    {
        for (auto it = component_.begin() ; it != component_.end() ; ++it)
            delete *it ;
    }

    void addComponent(Component *c){ component_.push_back(c); }
    void addComponent(std::vector<Component*> & c)
    {
        component_.insert(component_.end(), c.begin(), c.end());
    }

private:
    std::vector<Component*> component_ ;
    std::chrono::milliseconds duration_ ;
};
}
