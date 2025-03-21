#include "16_template_method/concrete_class.hpp"

#include <iostream>


namespace TemplateMethod
{

void ConcreteClass::primitive_operation1()
{
    std::cout << "I'm the ConcreteClass. I'm doing primitive operation 1."
      << std::endl;
}

void ConcreteClass::hook()
{
    std::cout << "I'm the ConcreteClass. I'm doing the hook." << std::endl;
}

void ConcreteClass::primitive_operation2()
{
    std::cout << "I'm the ConcreteClass. I'm doing primitive operation 2." <<
      std::endl;
}

} // namespace TemplateMethod
