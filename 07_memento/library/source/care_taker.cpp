#include <iostream>

#include "07_memento/care_taker.hpp"


CareTaker::CareTaker(Originator* originator)
: m_originator(originator)
{
    std::cout << "I'm the CareTaker. Just born." << std::endl;
}

void CareTaker::backup()
{
    std::cout << "I'm the Caretaker. Backing-up the Originator's state." <<
        std::endl;

    Memento* new_memento = m_originator->create_memento();
    m_past_states.push(new_memento);
}

void CareTaker::undo()
{
    std::cout << "I'm the Caretaker. Undoing change on Originator's state."
        << std::endl;

    Memento* old_memento = m_past_states.top();
    old_memento->restore();
}
