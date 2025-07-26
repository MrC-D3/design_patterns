#include "10_dirty_flag/dirty_flag.hpp"

#include <iostream>


namespace DirtyFlagNS
{

/*
** ChildClass implementation.
*/
ChildClass::ChildClass(const ParentClass& parent)
: m_parent{parent}
{}

void ChildClass::set_data(const int new_data)
{
    std::cout << "I'm the ChildClass. I'm updating my data just now.\n";

    m_data = new_data;
}

int ChildClass::get_data()
{
    if(m_dirty_flag)
    {
        std::cout << "I'm the ChildClass. I'm updating my data just now.\n";
        
        m_data = 2 * m_parent.get_data();
        m_dirty_flag = false;
    }

    return m_data;
}

void ChildClass::set_flag(const bool dirty)
{
    m_dirty_flag = dirty;
}

/*
** ParentClass implementation.
*/
ParentClass::ParentClass(const int data)
: m_data{data}, m_child{*this}
{}

void ParentClass::set_data(const int data)
{
    m_data = data;
    m_child.set_flag(true);
}

int ParentClass::get_data() const
{
    return m_data;
}

} // namespace DirtyFlagNS