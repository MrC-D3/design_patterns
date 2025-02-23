#include "07_memento/originator_concrete.hpp"


OriginatorConcrete::OriginatorConcrete(int state)
: m_state(state)
{
    std::cout << "I'm the Originator. Just born." << std::endl;
}

Memento* OriginatorConcrete::create_memento()
{
    return new MementoConcrete(this, m_state);
}

void OriginatorConcrete::restore_memento(Memento* memento)
{
    m_state = ((MementoConcrete*) memento)->get_state();
}

void OriginatorConcrete::set_state(int state)
{
    std::cout << "I'm the Originator. Setting a new state." << std::endl;

    m_state = state;
}

void OriginatorConcrete::show_state()
{
    std::cout << "I'm the Originator. My state is " << m_state << std::endl;
}
