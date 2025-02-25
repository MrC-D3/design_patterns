#include <iostream>

#include "08_prototype/PrototypeConcrete1.hpp"


PrototypeConcrete1::PrototypeConcrete1(int state)
  : m_state(state)
{}

PrototypeInterface* PrototypeConcrete1::clone()
{
    return new PrototypeConcrete1(m_state);
}

void PrototypeConcrete1::to_string()
{
    std::cout << "I'm a PrototypeConcrete" << m_state << std::endl;
}
