#ifndef MEDIATOR_INTERFACE_HPP
#define MEDIATOR_INTERFACE_HPP

#include <string>


namespace Mediator
{

class MediatorInterface
{
  public:
    virtual ~MediatorInterface() = default;

    virtual void notify(const std::string& notification) const = 0;
};

} // namespace Mediator

#endif // MEDIATOR_INTERFACE_HPP
