#ifndef MEMENTO_CONCRETE_HPP
#define MEMENTO_CONCRETE_HPP

#include "07_memento/memento_interface.hpp"
#include "07_memento/originator.hpp"


class OriginatorConcrete;

class MementoConcrete : public Memento
{
  public:
    MementoConcrete(OriginatorConcrete* originator, int state);

    void restore() override;

    int get_state();

  private:
    // Improvement: template the state type, so you Don't Repeat Yourself (DRY).
    int m_state;
    OriginatorConcrete* m_originator;
};

#endif
