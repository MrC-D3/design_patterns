#ifndef MEMENTO_CONCRETE_HPP
#define MEMENTO_CONCRETE_HPP

#include "07_memento/memento_interface.hpp"
#include "07_memento/originator.hpp"


class MementoConcrete : public Memento
{
  public:
    MementoConcrete(Originator* originator, int state);

    void restore() override;

    int get_state();

  private:
    int m_state;
    Originator* m_originator;
};

#endif
