#include "04_template_method/abstract_class.hpp"


namespace TemplateMethod
{

void AbstractClass::template_method()
{
    primitive_operation1();
    hook();
    primitive_operation2();
}

void AbstractClass::hook()
{}

} // namespace TemplateMethod
