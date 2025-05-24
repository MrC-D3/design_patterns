#include "12_observer/observer.hpp"

#include <iostream>


namespace ObserverNS
{

void Observer::update()
{
    std::cout << "I'm the Observer. Got an update from the Subject.\n";

    // Dynamic cast of m_subject, from SubjectInterface to Subject to eventually
    //   get specific info on the update.
    auto subject = std::dynamic_pointer_cast<Subject>(m_subject);
    std::cout << "I'm the Observer. That's the update: " << subject->getState()
      << ".\n";
}

} // namespace ObserverNS