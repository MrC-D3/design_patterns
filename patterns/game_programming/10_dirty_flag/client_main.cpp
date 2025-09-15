#include "10_dirty_flag/dirty_flag.hpp"

#include <iostream>


int main()
{
    using namespace DirtyFlagNS;
    ParentClass parent{1};
    std::cout << "Child data: " << parent.m_child.get_data() << ".\n";
    std::cout << "Child data: " << parent.m_child.get_data() << ".\n";

    parent.set_data(10);
    std::cout << "Child data: " << parent.m_child.get_data() << ".\n";
    std::cout << "Child data: " << parent.m_child.get_data() << ".\n";

    return 0;
}