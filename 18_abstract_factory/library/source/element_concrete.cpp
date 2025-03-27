#include "18_abstract_factory/element_concrete.hpp"

#include <iostream>


namespace AbstractFactoryNS
{

void ElementConcreteA1::doA()
{
    std::cout << "I'm ElementConcreteA1. Doing A's stuff in 1 of the possible \
      ways." << std::endl;
}

} // namespace AbstractFactoryNS
