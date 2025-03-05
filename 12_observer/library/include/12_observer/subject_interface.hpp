#ifndef SUBJECT_INTERFACE_HPP
#define SUBJECT_INTERFACE_HPP

#include "12_observer/observer_interface.hpp"

#include <vector>


class SubjectInterface
{
  public:
    virtual void attach(ObserverInterface* observer);
    virtual void detach(ObserverInterface* observer);
    virtual void notify();

  private:
    std::vector<ObserverInterface*> m_observers;
};

#endif