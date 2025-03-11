#include "12_observer/observer.hpp"

#include <iostream>


namespace ObserverNS
{
    
Observer::Observer(const std::shared_ptr<Subject>& subject)
  : m_subject(subject)
{
    subject->attach( this->shared_from_this() );
}

Observer::~Observer()
{
    m_subject->detach( this->shared_from_this() );
}

void Observer::update()
{
    m_state = m_subject->getState();

    std::cout << "I'm the Observer. The new state is: " << m_state << std::endl;
}

} // namespace ObserverNS