#ifndef SUBJECT_INTERFACE_HPP
#define SUBJECT_INTERFACE_HPP

#include "05_observer/observer_interface.hpp"

#include <vector>
#include <memory>


namespace ObserverNS
{

// The Subject can be a state machine and an event can be a state change.
class SubjectInterface
: public std::enable_shared_from_this<SubjectInterface>
{
  public:
    virtual ~SubjectInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    // Also called subscribe/unsubscribe.
    virtual void attach(const std::shared_ptr<ObserverInterface>& observer);
    virtual void detach(const std::shared_ptr<ObserverInterface>& observer);

    virtual void notify() const;

  private:
    // Classes vector<> and list<> let you remove while iterating, not set<>.
    // Subject can manage multiple events, each with its Observers list; in such
    //  case, the event/list must be specified in attach/detach methods.
    std::vector<std::weak_ptr<ObserverInterface>> m_observers;
};

} // namespace ObserverNS


#endif // SUBJECT_INTERFACE_HPP