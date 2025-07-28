#include "07_memento/originator_concrete.hpp"
#include "07_memento/memento_concrete.hpp"

#include <iostream>
#include <memory>


namespace Memento
{
    
OriginatorConcrete::OriginatorConcrete(const std::int64_t state)
: m_state{state}
{
    std::cout << "I'm the Originator. Just born.\n";
}

std::unique_ptr<MementoInterface> OriginatorConcrete::create_memento() const
{
    return std::make_unique<MementoConcrete>(
      std::const_pointer_cast<OriginatorConcrete>(shared_from_this()), 
      m_state
      );
}

void OriginatorConcrete::set_state(const std::int64_t state)
{
    std::cout << "I'm the Originator. Setting a new state.\n";

    m_state = state;
}

void OriginatorConcrete::show_state() const
{
    std::cout << "I'm the Originator. My state is " << m_state << ".\n";
}

} // namespace Memento