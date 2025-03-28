#include "19_composite/composite.hpp"
#include <iostream>


namespace CompositeNS
{

void Composite::act()
{
    for(auto i : m_children)
    {
        i->act();
    }

    std::cout << "I'm a Composite. I'm acting." << std::endl;
}

void Composite::add(Component* child)
{
    m_children.push_back(child);
}

} // namespace CompositeNS
