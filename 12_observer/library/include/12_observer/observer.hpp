#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "12_observer/observer_interface.hpp"
#include "12_observer/subject.hpp"

#include <memory>


namespace ObserverNS
{
  
class Observer final : 
  public ObserverInterface,
  public std::enable_shared_from_this<Observer>
{
  public:
    explicit Observer(const std::shared_ptr<Subject>& subject);
    ~Observer();
    
    void attach() override;
    void update() override;

  private:
    // Avoid cyclic shared_ptr Observer->Subject->Observer.
    std::weak_ptr<Subject> m_subject;
    std::int64_t m_state;
};

} // namespace ObserverNS

#endif