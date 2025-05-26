#include "16_template_method/concrete_class.hpp"

#include <iostream>


namespace TemplateMethod
{

void ConcreteClass::primitive_operation1()
{
    std::cout << "I'm the ConcreteClass. I'm doing primitive operation 1.\n";
}

void ConcreteClass::hook()
{
    std::cout << "I'm the ConcreteClass. I'm doing the hook.\n";
}

void ConcreteClass::primitive_operation2()
{
    std::cout << "I'm the ConcreteClass. I'm doing primitive operation 2.\n";
}

} // namespace TemplateMethod
