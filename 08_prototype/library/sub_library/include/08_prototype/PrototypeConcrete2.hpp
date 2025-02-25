#ifndef PROTOTYPE_CONCRETE2_HPP
#define PROTOTYPE_CONCRETE2_HPP

#include <iostream>

#include "08_prototype/PrototypeInterface.hpp"


class PrototypeConcrete2 : public PrototypeInterface
{
  public:
    PrototypeConcrete2(int state = 2);
    
    PrototypeInterface* clone() override;

    void to_string() override;

  private:
    int m_state;
};

#endif