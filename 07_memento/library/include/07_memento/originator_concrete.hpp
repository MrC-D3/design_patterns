#ifndef ORIGINATOR_CONCRETE_HPP
#define ORIGINATOR_CONCRETE_HPP

#include <iostream>

#include "07_memento/originator.hpp"


class OriginatorConcrete : public Originator
{
  public:
    OriginatorConcrete(int state = 0);

    Memento* create_memento() override;

    void set_state(int state);

    void show_state();

  private:
    int m_state = 0;
};

#endif
