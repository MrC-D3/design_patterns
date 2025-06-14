#ifndef DECORATOR_CONCRETE_HPP
#define DECORATOR_CONCRETE_HPP

#include "14_decorator/decorator_interface.hpp"

#include <memory>


namespace Decorator
{

class DecoratorConcrete final : public DecoratorInterface
{
  public:
    explicit DecoratorConcrete(std::unique_ptr<ComponentInterface>&& component);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void behavior() override;
};

} // namespace Decorator


#endif // DECORATOR_CONCRETE_HPP
