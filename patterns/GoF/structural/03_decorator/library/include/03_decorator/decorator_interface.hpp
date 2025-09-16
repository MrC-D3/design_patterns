#ifndef DECORATOR_INTERFACE_HPP
#define DECORARTOR_INTERFACE_HPP

#include "03_decorator/component_interface.hpp"

#include <memory>
#include <iostream>
#include <functional>


namespace Decorator
{

/*
** Classic solution with basic inheritance.
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
** Alternative solution 01: with CRTP (Curiously Recurring Template Pattern).
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

/*
** Alternative solution 02: function decorator.
*/
template <typename ReturnType, typename... Args>
class DecoratorFunction
{
  public:
    // Don't use explicit type input parameter (i.e. std::function<>) or you
    //  can't pass lambdas.
    template<typename F>
    explicit DecoratorFunction(F&& function_to_decorate)
    : m_function(std::forward<F>(function_to_decorate))
    {}

    // Use: 
    // - "... Args" to declare a pack-type;
    // - "Args..." to refer to the pack-type;
    // - "Args... args" to declare a pack-variable of a pack-type;
    // - "args..." to refer to the pack-variable.
    ReturnType operator()(Args&&... args)
    {
        // Do something prior.
        
        // Without <Args> it compiles, but it's wrong because it doesn't know 
        //  how to forward the args.  
        auto to_return = m_function(std::forward<Args>(args)...);
        
        // Do something after.
        return to_return;
    }

  private:
    std::function<ReturnType(Args...)> m_function;
};

} // namespace Decorator

#endif // DECORATOR_INTERFACE_HPP