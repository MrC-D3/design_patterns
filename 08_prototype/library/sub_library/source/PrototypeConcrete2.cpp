#include <iostream>

#include "08_prototype/PrototypeConcrete2.hpp"


namespace Prototype
{

std::unique_ptr<PrototypeInterface> PrototypeConcrete2::clone() const
{
    return std::make_unique<PrototypeConcrete2>();
}

void PrototypeConcrete2::to_string() const
{
    std::cout << "I'm a PrototypeConcrete2. State: 2.\n";
}

} // namespace Prototype