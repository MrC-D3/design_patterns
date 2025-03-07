#include "07_memento/memento_concrete.hpp"


namespace Memento
{

MementoConcrete::MementoConcrete(
  const std::unique_ptr<OriginatorConcrete>& originator, 
  const std::int64_t& state)
  : m_state(state),
    m_originator(originator)
{}

void MementoConcrete::restore() const
{
    m_originator->set_state(m_state);
}

std::int64_t MementoConcrete::get_state() const
{
    return m_state;
}

} // namespace Memento
