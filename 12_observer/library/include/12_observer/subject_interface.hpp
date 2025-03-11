#ifndef SUBJECT_INTERFACE_HPP
#define SUBJECT_INTERFACE_HPP

#include "12_observer/observer_interface.hpp"

#include <vector>
#include <memory>


namespace ObserverNS
{
  
class SubjectInterface
{
  public:
    virtual ~SubjectInterface() = default;

    virtual void attach(const std::shared_ptr<ObserverInterface>& observer);
    virtual void detach(const std::shared_ptr<ObserverInterface>& observer);
    virtual void notify() const;

  private:
    std::vector<std::shared_ptr<ObserverInterface>> m_observers;
};

} // namespace ObserverNS


#endif // SUBJECT_INTERFACE_HPP