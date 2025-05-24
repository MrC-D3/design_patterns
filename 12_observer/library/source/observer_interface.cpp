#include "12_observer/observer_interface.hpp"
#include "12_observer/subject_interface.hpp"


namespace ObserverNS
{

ObserverInterface::~ObserverInterface()
{
    m_subject->detach( this->shared_from_this() );
}

void ObserverInterface::store_subject(
  const std::shared_ptr<SubjectInterface>& subject)
{
    m_subject = subject;
}

} // namespace ObserverNS