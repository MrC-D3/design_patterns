#include "09_data_locality/data_locality.hpp"

#include <iostream>


namespace DataLocalityNS
{

Component1::Component1(const Container& container)
: m_container{container}
{}

void Component1::do_something()
{
    std::cout << "Still the Component1. Doing something.\n";
}

} // DataLocalityNS