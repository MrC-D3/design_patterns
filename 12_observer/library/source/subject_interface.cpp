#include "12_observer/subject_interface.hpp"


namespace ObserverNS
{
    
void SubjectInterface::attach(const std::shared_ptr<ObserverInterface>& observer)
{
    m_observers.push_back(observer);
}

void SubjectInterface::detach(const std::shared_ptr<ObserverInterface>& observer)
{
    for(auto it = m_observers.begin(); it != m_observers.end(); it++)
    {
        if(observer == *it)
        {
            m_observers.erase(it);
            break;
        }
    }
}

void SubjectInterface::notify() const 
{
    for(auto it = m_observers.begin(); it != m_observers.end(); it++)
    {
        (*it)->update();
    }
}

} // namespace ObserverNS