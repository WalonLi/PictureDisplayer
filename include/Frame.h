/**
    Provide by Walon Li, YJ Fang

    File IPlay.h
**/

#include <chrono>
#include <vector>
#include "Component/Component.h"

namespace pdr
{
class Frame
{
public:
    explicit Frame(std::chrono::milliseconds d) : duration(d) {}
    ~Frame()
    {
        for (auto it = component.begin() ; it != component.end() ; ++it)
            delete it ;
    }

    void addComponent(Component *c){ component.push_back(c); }
    void addComponent(std::vector<Component*> & c) { component += c; }

private:
    std::vector<Component*> component ;
    std::chrono::milliseconds duration ;
}
}
