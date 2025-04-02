#ifndef DECORATOR_CONCRETE_HPP
#define DECORATOR_CONCRETE_HPP

#include "14_decorator/decorator_interface.hpp"

#include <memory>


namespace Decorator
{

class DecoratorConcrete final : public DecoratorInterface
{
  public:
    ~DecoratorConcrete() = default;
    DecoratorConcrete(std::unique_ptr<ComponentInterface>&& component);

    // Delete copy methods because of unique_ptr.
    DecoratorConcrete(const DecoratorConcrete& origin) = delete;
    DecoratorConcrete& operator=(const DecoratorConcrete& origin) = delete;

    DecoratorConcrete(DecoratorConcrete&& origin) = default;
    DecoratorConcrete& operator=(DecoratorConcrete&& origin) = default;

    void behavior() override;
};

} // namespace Decorator


#endif // DECORATOR_CONCRETE_HPP
