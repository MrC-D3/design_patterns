#include "12_observer/observer.hpp"

#include <iostream>


namespace ObserverNS
{
    
Observer::Observer(const std::shared_ptr<Subject>& subject)
  : m_subject(subject)
{
    // Can't call shared_from_this() in the c'tor.
}

Observer::~Observer()
{
    if( auto subject = m_subject.lock() )
    {
        subject->detach( this->shared_from_this() );
    }
}

void Observer::attach()
{
    if( auto subject = m_subject.lock() )
    {
        subject->attach( this->shared_from_this() );
    }
}

void Observer::update()
{
    if( auto subject = m_subject.lock() )
    {
        m_state = subject->getState();
    }

    std::cout << "I'm the Observer. The new state is: " << m_state << std::endl;
}

} // namespace ObserverNS