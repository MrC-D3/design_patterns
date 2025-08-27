#include <iostream>

#include "04_prototype/PrototypeConcrete.hpp"


namespace Prototype
{

/*
** PrototypeConcrete1 implemenetation.
*/
std::unique_ptr<PrototypeInterface> PrototypeConcrete1::clone() const
{
    return std::make_unique<PrototypeConcrete1>();
}

void PrototypeConcrete1::to_string() const
{
    std::cout << "I'm a PrototypeConcrete1. State: 1.\n";
}

/*
** PrototypeConcrete2 implemenetation.
*/
std::unique_ptr<PrototypeInterface> PrototypeConcrete2::clone() const
{
    return std::make_unique<PrototypeConcrete2>();
}

void PrototypeConcrete2::to_string() const
{
    std::cout << "I'm a PrototypeConcrete2. State: 2.\n";
}

} // namespace Prototype