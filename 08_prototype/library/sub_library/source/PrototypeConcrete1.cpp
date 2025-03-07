#include <iostream>

#include "08_prototype/PrototypeConcrete1.hpp"


namespace Prototype
{
  
PrototypeConcrete1::PrototypeConcrete1(const std::int64_t& state)
  : m_state(state)
{}

std::unique_ptr<PrototypeInterface> PrototypeConcrete1::clone() const
{
    return std::make_unique<PrototypeConcrete1>(m_state);
}

void PrototypeConcrete1::to_string() const
{
    std::cout << "I'm a PrototypeConcrete" << m_state << std::endl;
}

} // namespace Prototype