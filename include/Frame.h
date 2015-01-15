/**
    Provide by Walon Li, YJ Fang

    File Frame.h
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
    explicit Frame(std::chrono::milliseconds d) ;
    ~Frame() ;

    void addComponent(Component *c){ components_.push_back(c); }
    void addComponent(std::vector<Component*> & c)
    {
        components_.insert(components_.end(), c.begin(), c.end());
    }

    size_t getComponentsCount () const { return components_.size() ;}
    std::vector<Component*> & getComponents() {return components_;}
    Component* getComponent(int i) const { return components_[i] ;}

    std::chrono::milliseconds getDuration() const {return duration_;}

private:
    std::vector<Component*> components_ ;
    std::chrono::milliseconds duration_ ;
};
}
