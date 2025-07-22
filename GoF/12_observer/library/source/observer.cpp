#include "12_observer/observer.hpp"

#include <iostream>


namespace ObserverNS
{

/*
** Implementation of classic Observer.
*/
void Observer::update()
{
    std::cout << "I'm the Observer. Got an update from the Subject.\n";

    // Dynamic cast of m_subject, from SubjectInterface to Subject to eventually
    //   get specific info on the update.
    auto subject = std::dynamic_pointer_cast<Subject>(m_subject);
    std::cout << "I'm the Observer. That's the update: " << subject->getState()
      << ".\n";
}

/*
** Implementation of safe Observer.
*/
Listener::Listener() 
: m_newData{false}, m_keepGoing{false} 
{}

void Listener::stop() 
{ 
    m_keepGoing = false; 
    m_condvar.notify_all(); 
}

void Listener::for_every_change()
{
    m_keepGoing = true;
    while (m_keepGoing)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condvar.wait(lock, [&]{ return m_newData || !m_keepGoing; });
        m_newData = false; // no more data
        std::string temp = m_info;
        lock.unlock();
        fooChanged(temp);
    }
}

void Listener::check_for_change()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_newData) 
    {
        m_newData = false;
        std::string temp = m_info;
        lock.unlock();
        fooChanged(temp);
    }
}

void Listener::inform_fooChanged(std::string s)
{
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        //push onto a queue usually
        m_info = s;
        m_newData = true;
    }
    m_condvar.notify_all();
}

} // namespace ObserverNS