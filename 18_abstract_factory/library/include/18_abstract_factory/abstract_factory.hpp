#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include "18_abstract_factory/element_interface.hpp"
#include <memory>


namespace AbstractFactoryNS
{

class AbstractFactory
{
  public:
    virtual ~AbstractFactory() = default;
    AbstractFactory() = default;

    AbstractFactory(const AbstractFactory& origin) = default;
    AbstractFactory& operator=(const AbstractFactory& origin) = default;

    AbstractFactory(AbstractFactory&& origin) = default;
    AbstractFactory& operator=(AbstractFactory&& origin) = default;

    virtual std::unique_ptr<ElementInterfaceA> factoryElementA() = 0;
    // Potentially factoryElementB() and other factory methods.
};

} // namesapce AbstractFactoryNS


#endif // ABSTRACT_FACTORY_HPP