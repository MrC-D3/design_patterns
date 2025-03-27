#include "18_abstract_factory/concrete_factory.hpp"


namespace AbstractFactoryNS
{

ElementInterfaceA* ConcreteFactory::factoryElementA()
{
    return new ElementConcreteA1();
}

} // namespace AbstractFactoryNS
