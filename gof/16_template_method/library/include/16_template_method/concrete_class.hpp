#ifndef CONCRETE_CLASS_HPP
#define CONCRETE_CLASS_HPP

#include "16_template_method/abstract_class.hpp"


namespace TemplateMethod
{

class ConcreteClass final : public AbstractClass
{
  protected:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    
    void primitive_operation1() override;

    void hook() override;

    void primitive_operation2() override;
};

} // namespace TemplateMethod


#endif // CONCRETE_CLASS_HPP