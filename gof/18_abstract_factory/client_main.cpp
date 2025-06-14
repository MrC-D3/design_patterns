#include "18_abstract_factory/concrete_factory.hpp"
#include "18_abstract_factory/element_interface.hpp"


using namespace AbstractFactoryNS;

int main()
{
    ConcreteFactory factory;

    auto elementA = factory.factoryElementA();

    elementA->doA();
    
    return 0;
}