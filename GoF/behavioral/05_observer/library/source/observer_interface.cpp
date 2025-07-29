#include "05_observer/observer_interface.hpp"
#include "05_observer/subject_interface.hpp"

#include <iostream>


namespace ObserverNS
{

ObserverInterface::~ObserverInterface()
{
    std::cout << "I'm the Observer. D'tor call.\n";

    // Can't call shared_from_this() in d'tor; so: you can call a general
    //  Subject's detach method here to delete its weak_ptr to the dying 
    //  Observer, or the weak_ptr can be deleted during the notify()'s loop.
}

void ObserverInterface::store_subject(
  const std::shared_ptr<SubjectInterface>& subject)
{
    std::cout << "I'm the Observer. Storing the Subject I'm attached to.\n";

    m_subject = subject;
}

} // namespace ObserverNS