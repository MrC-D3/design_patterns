#ifndef CARE_TAKER_HPP
#define CARE_TAKER_HPP

#include <stack>
#include "07_memento/originator.hpp"
#include "07_memento/memento_interface.hpp"


class CareTaker
{
  public:
    CareTaker(Originator* originator);

    void backup();

    void undo();

  private:
    // Originator is needed because is the only one that can generate a Memento.
    Originator* m_originator = nullptr;
    std::stack<Memento*> m_past_states;
};

#endif
