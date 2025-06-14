#ifndef OBSERVER_INTERFACE_HPP
#define OBSERVER_INTERFACE_HPP

#include <memory>


namespace ObserverNS
{
  
class SubjectInterface;

class ObserverInterface
: public std::enable_shared_from_this<ObserverInterface>
{
  public:
    virtual ~ObserverInterface();
    // Default c'tors and operator= overloads, both copy and move.

    virtual void store_subject(
      const std::shared_ptr<SubjectInterface>& subject);

    // Alternative: pass some data as parameter.
    virtual void update() = 0;

  protected:
    std::shared_ptr<SubjectInterface> m_subject;
};

} // namespace Observer


#endif // OBSERVER_INTERFACE_HPP