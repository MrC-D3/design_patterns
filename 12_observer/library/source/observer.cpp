#include "12_observer/observer.hpp"


Oberver::Observer(Subject* subject)
  : m_subject(subject)
{
    subject->attach(this);
}

Observer::~Observer()
{
    m_subject->detach(this);
}

void Oberver::update()
{
    m_state = m_subject->getState();
}