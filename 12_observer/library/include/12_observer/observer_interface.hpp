#ifndef OBSERVER_INTERFACE_HPP
#define OBSERVER_INTERFACE_HPP

#include "12_observer/subject_interface.hpp"


class ObserverInterface
{
  public:
    virtual void attach(SubjectInterface* subject) = 0;
    virtual void detach() = 0;

  private:
    SubjectInterface* m_subject;
};

#endif