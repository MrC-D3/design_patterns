#ifndef PROTOTYPE_CONCRETE_HPP
#define PROTOTYPE_CONCRETE_HPP

#include "08_prototype/PrototypeInterface.hpp"


class PrototypeConcrete : public PrototypeInterface
{
  public:
    PrototypeConcrete(int state)
      : m_state(state)
    {}
    
    PrototypeInterface* clone() override
    {
        return new PrototypeConcrete(m_state);
    }

  private:
    int m_state;
};

#endif