#include <iostream>

#include "08_prototype/PrototypeConcrete2.hpp"


namespace Prototype
{
  
PrototypeConcrete2::PrototypeConcrete2(const std::int64_t& state)
  : m_state(state)
{}

std::unique_ptr<PrototypeInterface> PrototypeConcrete2::clone() const
{
    return std::make_unique<PrototypeConcrete2>(m_state);
}

void PrototypeConcrete2::to_string() const
{
    std::cout << "I'm a PrototypeConcrete" << m_state << std::endl;
}

} // namespace Prototype