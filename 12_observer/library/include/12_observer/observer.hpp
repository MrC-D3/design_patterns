#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "12_observer/observer_interface.hpp"
#include "12_observer/subject.hpp"


class Observer : public ObserverInterface
{
  public:
    Observer(Subject* subject);
    ~Observer();
    
    void update() override;

  private:
    Subject* m_subject;
    int m_state;
};

#endif