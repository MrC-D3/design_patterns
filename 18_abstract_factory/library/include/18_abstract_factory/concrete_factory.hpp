#ifndef CONCRETE_FACTORY_HPP
#define CONCRETE_FACTORY_HPP

#include "18_abstract_factory/abstract_factory.hpp"
#include "18_abstract_factory/element_concrete.hpp"
#include <memory>


namespace AbstractFactoryNS
{

class ConcreteFactory final : public AbstractFactory
{
  public:
    ~ConcreteFactory() = default;
    ConcreteFactory() = default;

    ConcreteFactory(const ConcreteFactory& origin) = default;
    ConcreteFactory& operator=(const ConcreteFactory& origin) = default;

    ConcreteFactory(ConcreteFactory&& origin) = default;
    ConcreteFactory& operator=(ConcreteFactory&& origin) = default;

    std::unique_ptr<ElementInterfaceA> factoryElementA() override;
};

} // namespace AbstractFactoryNS


#endif // CONCRETE_FACTORY_HPP