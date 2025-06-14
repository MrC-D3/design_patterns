#ifndef PROTOTYPE_INTERFACE_HPP
#define PROTOTYPE_INTERFACE_HPP

#include <memory>


namespace Prototype
{

// The Base class is not strictly needed; the Pattern stays in the clone method.
class PrototypeInterface
{
  public:
    virtual ~PrototypeInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual std::unique_ptr<PrototypeInterface> clone() const = 0;

    // Added for debug reasons.
    virtual void to_string() const = 0;
};

} // namespace Prototype


#endif // PROTOTYPE_INTERFACE_HPP