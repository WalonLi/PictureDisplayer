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
        for (auto it = components_.begin() ; it != components_.end() ; ++it)
            delete *it ;
    }

    void addComponent(Component *c){ components_.push_back(c); }
    void addComponent(std::vector<Component*> & c)
    {
        components_.insert(components_.end(), c.begin(), c.end());
    }

    size_t getComponentsCount () { return components_.size() ;}
    std::vector<Component*> & getComponents(){ return components_ ; }
    Component* getComponent(int i){ return components_[i] ;}

private:
    std::vector<Component*> components_ ;
    std::chrono::milliseconds duration_ ;
};
}
