#ifndef CONCRETE_FACTORY_HPP
#define CONCRETE_FACTORY_HPP

#include "18_abstract_factory/abstract_factory.hpp"
#include "18_abstract_factory/element_concrete.hpp"


namespace AbstractFactoryNS
{

class ConcreteFactory : public AbstractFactory
{
  public:
    ElementInterfaceA* factoryElementA() override;
};

} // namespace AbstractFactoryNS


#endif // CONCRETE_FACTORY_HPP