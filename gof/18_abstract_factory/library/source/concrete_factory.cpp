#include "18_abstract_factory/concrete_factory.hpp"


namespace AbstractFactoryNS
{

std::unique_ptr<ElementInterfaceA> ConcreteFactory::factoryElementA()
{
    return std::make_unique<ElementConcreteA1>();
}

} // namespace AbstractFactoryNS
