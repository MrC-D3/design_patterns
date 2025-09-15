#include "04_template_method/abstract_class.hpp"
#include "04_template_method/concrete_class.hpp"


using namespace TemplateMethod;

int main()
{
    ConcreteClass concrete;

    concrete.template_method();

    return 0;
}