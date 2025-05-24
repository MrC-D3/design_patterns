#include "12_observer/subject.hpp"

#include <iostream>


namespace ObserverNS
{
    
void Subject::setState(const std::int64_t state)
{
    std::cout << "I'm the Subject. Updating the state.\n";

    m_state = state;
    notify();
}

const std::int64_t& Subject::getState() const
{
    return m_state;
}

} // namespace ObserverNS