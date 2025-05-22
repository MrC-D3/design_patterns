#ifndef MEDIATOR_INTERFACE_HPP
#define MEDIATOR_INTERFACE_HPP

#include <string>
#include <memory>


namespace Mediator
{

class MediatorInterface : public std::enable_shared_from_this<MediatorInterface>
{
  public:
    virtual ~MediatorInterface() = default;

    // Default c'tors and operator= overloads, both copy and move.

    virtual void notify(const std::string& notification) const = 0;
};

} // namespace Mediator


#endif // MEDIATOR_INTERFACE_HPP
