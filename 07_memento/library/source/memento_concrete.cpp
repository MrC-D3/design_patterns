#include "07_memento/memento_concrete.hpp"


MementoConcrete::MementoConcrete(Originator* originator, int state)
: m_state(state),
  m_originator(originator)
{}

void MementoConcrete::restore()
{
    m_originator->restore_memento(this);
}

int MementoConcrete::get_state()
{
    return m_state;
}
