#ifndef CONCRETE_FACTORY_HPP
#define CONCRETE_FACTORY_HPP

#include "03_abstract_factory/abstract_factory.hpp"
#include "03_abstract_factory/element_concrete.hpp"
#include <memory>


namespace AbstractFactoryNS
{

class ConcreteFactory final : public AbstractFactory
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    std::unique_ptr<ElementInterfaceA> factoryElementA() override;
};

} // namespace AbstractFactoryNS


#endif // CONCRETE_FACTORY_HPP