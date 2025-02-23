#ifndef ORIGINATOR_HPP
#define ORIGINATOR_HPP

#include "07_memento/memento_interface.hpp"


class Originator
{
  public:
    virtual Memento* create_memento() = 0;
    virtual void restore_memento(Memento* memento) = 0;
};

#endif
