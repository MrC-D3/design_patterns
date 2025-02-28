#include "07_memento/memento_concrete.hpp"
#include "07_memento/originator_concrete.hpp"


MementoConcrete::MementoConcrete(OriginatorConcrete* originator, int state)
: m_state(state),
  m_originator(originator)
{}

void MementoConcrete::restore()
{
    m_originator->set_state(m_state);
}

int MementoConcrete::get_state()
{
    return m_state;
}
