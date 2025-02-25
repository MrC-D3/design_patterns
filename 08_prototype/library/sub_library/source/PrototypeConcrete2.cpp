#include <iostream>

#include "08_prototype/PrototypeConcrete2.hpp"


PrototypeConcrete2::PrototypeConcrete2(int state)
  : m_state(state)
{}

PrototypeInterface* PrototypeConcrete2::clone()
{
    return new PrototypeConcrete2(m_state);
}

void PrototypeConcrete2::to_string()
{
    std::cout << "I'm a PrototypeConcrete" << m_state << std::endl;
}
