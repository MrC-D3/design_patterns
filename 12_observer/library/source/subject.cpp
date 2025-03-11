#include "12_observer/subject.hpp"


namespace ObserverNS
{
    
void Subject::setState(const std::int64_t& state)
{
    m_state = state;
    notify();
}

std::int64_t Subject::getState() const
{
    return m_state;
}

} // namespace ObserverNS