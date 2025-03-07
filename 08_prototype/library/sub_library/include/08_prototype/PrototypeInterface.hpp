#ifndef PROTOTYPE_INTERFACE_HPP
#define PROTOTYPE_INTERFACE_HPP

#include <memory>


namespace Prototype
{
  
class PrototypeInterface
{
  public:
    virtual ~PrototypeInterface() = default;

    virtual std::unique_ptr<PrototypeInterface> clone() const = 0;

    virtual void to_string() const = 0;
};

} // namespace Prototype


#endif // PROTOTYPE_INTERFACE_HPP