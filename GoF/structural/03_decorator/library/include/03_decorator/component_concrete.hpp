#ifndef COMPONENT_CONCRETE_HPP
#define COMPONENT_CONCRETE_HPP

#include "03_decorator/component_interface.hpp"


namespace Decorator
{

// Can't be final because DecoratorAdvanced inherits from it.
class ComponentConcrete : public ComponentInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void behavior() override;
};

} // namespace Decorator


#endif // COMPONENT_CONCRETE_HPP