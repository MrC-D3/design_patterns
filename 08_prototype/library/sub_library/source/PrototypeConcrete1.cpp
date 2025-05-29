#include <iostream>

#include "08_prototype/PrototypeConcrete1.hpp"


namespace Prototype
{

std::unique_ptr<PrototypeInterface> PrototypeConcrete1::clone() const
{
    return std::make_unique<PrototypeConcrete1>();
}

void PrototypeConcrete1::to_string() const
{
    std::cout << "I'm a PrototypeConcrete1. State: 1.\n";
}

} // namespace Prototype