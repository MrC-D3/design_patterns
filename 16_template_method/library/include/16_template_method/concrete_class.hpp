#ifndef CONCRETE_CLASS_HPP
#define CONCRETE_CLASS_HPP

#include "16_template_method/abstract_class.hpp"


namespace TemplateMethod
{

class ConcreteClass final : public AbstractClass
{
  protected:
    ~ConcreteClass() = default;
    ConcreteClass() = default;

    ConcreteClass(const ConcreteClass& origin) = default;
    ConcreteClass& operator=(const ConcreteClass& origin) = default;

    ConcreteClass(ConcreteClass&& origin) = default;
    ConcreteClass& operator=(ConcreteClass&& origin) = default;
    
    void primitive_operation1() override;

    void hook() override;

    void primitive_operation2() override;
};

} // namespace TemplateMethod

#endif // CONCRETE_CLASS_HPP