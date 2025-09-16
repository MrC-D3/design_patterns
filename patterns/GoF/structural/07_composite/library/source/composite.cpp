#include "07_composite/composite.hpp"
#include <iostream>


namespace CompositeNS
{

void Composite::act()
{
    std::cout << "I'm a Composite. I'm acting.\n";

    for(auto& i : m_children)
    {
        i->act();
    }
}

void Composite::add(std::unique_ptr<Component>&& child)
{
    m_children.emplace_back( std::move(child) );
}

} // namespace CompositeNS
