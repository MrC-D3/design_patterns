#include "12_observer/subject_interface.hpp"


void SubjectInterface::attach(ObserverInterface* observer)
{
    m_observers.push_back(observer);
}

void SubjectInterface::detach(ObserverInterface* observer)
{
    for(auto it = m_observers.begin(); it != m_observers.end(); it++)
    {
        if(observer == *it)
        {
            m_observers.remove(it);
            break;
        }
    }
}

void SubjectInterface::notify()
{
    for(auto it = m_observers.begin(); it != m_observers.end(); it++)
    {
        it->update();
    }
}