#include "05_observer/subject.hpp"
#include "05_observer/observer.hpp"

#include <iostream>


namespace ObserverNS
{

/*
** Solution 01: Classic.
*/
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

/*
** Solution 02: Thread Safe.
** From "Tony Van Eerd: Thread-safe Observer Pattern - You're doing it wrong".
*/
void SubjectSafe::set_state(std::string state)
{
    // TODO because this "notify" variable is not used...
    bool notify = false;
    {
        std::lock_guard<std::recursive_mutex> lock(m_mutex);
        if (m_state != state) 
        {
            m_state = state;
            notifyListeners();
        }
    }
}

std::string SubjectSafe::get_state() 
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);  
    return m_state; 
}

void SubjectSafe::addListener(Listener * listener) 
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    m_listeners.push_back(listener);
}

bool SubjectSafe::removeListener(Listener * listener) 
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    for (auto it = m_listeners.end();  it != m_listeners.begin();  )
    {
        it--;
        if (*it == listener) 
        {
            m_listeners.erase(it);
            return true;
        }
    }
    return false;
}

void SubjectSafe::notifyListeners() 
{
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    for (auto listener : m_listeners)
    {
        listener->inform_fooChanged(get_state());
    }
}

} // namespace ObserverNS