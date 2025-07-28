#ifndef DECORATOR_INTERFACE_HPP
#define DECORARTOR_INTERFACE_HPP

#include "14_decorator/component_interface.hpp"

#include <memory>
#include <iostream>


namespace Decorator
{

/*
** Standard solution with basic inheritance.
*/
class DecoratorInterface : public ComponentInterface
{
  public:
    virtual ~DecoratorInterface() = default;
    explicit DecoratorInterface(std::unique_ptr<ComponentInterface>&& component);
    // Default c'tors and operator= overloads, both copy and move.

    void behavior() override;

  protected:
    std::unique_ptr<ComponentInterface> m_component;
};

/*
** Advanced solution with inheritance and template.
*/
template <typename Type> class DecoratorAdvanced : public Type
{
    static_assert(std::is_base_of<ComponentInterface, Type>::value, 
      "Type must be a ComponentInterface.");
  
    public:
      template <typename...Args> DecoratorAdvanced(char decoration, Args ...args)
      : Type{ std::forward<Args>(args)... },
        m_decoration{ decoration }
      {}

      void behavior() override
      {
          Type::behavior();
          
          std::cout << "I'm DecoratorAdvanced. Here my decoration: " << 
            m_decoration << ".\n";
      }

  private:
    char m_decoration;
};

} // namespace Decorator

#endif // DECORATOR_INTERFACE_HPP