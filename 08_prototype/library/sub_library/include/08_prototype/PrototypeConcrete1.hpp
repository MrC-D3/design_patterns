#ifndef PROTOTYPE_CONCRETE1_HPP
#define PROTOTYPE_CONCRETE1_HPP

#include <iostream>

#include "08_prototype/PrototypeInterface.hpp"


class PrototypeConcrete1 : public PrototypeInterface
{
  public:
    PrototypeConcrete1(int state = 1);
    
    PrototypeInterface* clone() override;

    void to_string() override;

  private:
    int m_state;
};

#endif