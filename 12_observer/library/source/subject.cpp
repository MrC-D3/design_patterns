#include "12_observer/subject.hpp"


void Subject::setState(int state)
{
    m_state = state;
    notify();
}

int Subject::getState()
{
    return m_state;
}