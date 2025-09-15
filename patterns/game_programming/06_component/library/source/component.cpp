#include "06_component/component.hpp"
#include <iostream>


namespace ComponentNS
{

void Component1::do_something()
{
    std::cout << "I'm Component1.\n";
}

void Component2::do_something()
{
    std::cout << "I'm Component2.\n";
}

Container::Container(Component1& component1, Component2& component2)
: m_component1{component1}, m_component2{component2}
{}

void Container::do_all()
{
    std::cout << "I'm the Container. I'm going to use my Components.\n";

    m_component1.do_something();
    // Here, the Container can potentially sort messages between Components 
    //  (like Moderator pattern).
    // Each Component can consume the Container's state, so the order of the
    //  Components is important.
    m_component2.do_something();
}

} // namespace ComponentNS
