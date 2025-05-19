#include "19_composite/composite.hpp"
#include <iostream>


namespace CompositeNS
{

void Composite::act()
{
    for(auto& i : m_children)
    {
        i->act();
    }

    std::cout << "I'm a Composite. I'm acting." << std::endl;
}

void Composite::add(std::unique_ptr<Component>&& child)
{
    m_children.emplace_back( std::move(child) );
}

} // namespace CompositeNS
