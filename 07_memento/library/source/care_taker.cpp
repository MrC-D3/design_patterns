#include "07_memento/care_taker.hpp"

#include <iostream>


namespace Memento
{
    
CareTaker::CareTaker(const std::shared_ptr<OriginatorInterface>& originator)
: m_originator(originator)
{
    std::cout << "I'm the CareTaker. Just born." << std::endl;
}

void CareTaker::backup()
{
    std::cout << "I'm the Caretaker. Backing-up the Originator's state." <<
        std::endl;

    auto new_memento = m_originator->create_memento();
    m_past_states.push( std::move(new_memento) );
}

void CareTaker::undo()
{
    std::cout << "I'm the Caretaker. Undoing change on Originator's state."
        << std::endl;

    if (!m_past_states.empty())
    {
        m_past_states.top()->restore();
        m_past_states.pop();
    }
}

} // namespace Memento
