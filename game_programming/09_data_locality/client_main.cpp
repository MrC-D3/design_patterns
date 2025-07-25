#include "09_data_locality/data_locality.hpp"
#include <vector>


int main()
{
    using namespace DataLocalityNS;
    std::vector<Component1> components1{ Component1{0u}, Component1{1u}, Component1{2u} };

    for(Container i = 0u; i < components1.size(); i++)
    {
        components1[i].do_something();
    }

    return 0;
}