#include "12_observer/observer.hpp"

#include <iostream>


Observer::Observer(Subject* subject)
  : m_subject(subject)
{
    subject->attach(this);
}

Observer::~Observer()
{
    m_subject->detach(this);
}

void Observer::update()
{
    m_state = m_subject->getState();

    std::cout << "I'm the Observer. The new state is: " << m_state << std::endl;
}