#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include "18_abstract_factory/element_interface.hpp"


namespace AbstractFactoryNS
{

class AbstractFactory
{
  public:
    virtual ~AbstractFactory() = default;

    virtual ElementInterfaceA* factoryElementA() = 0;
    // Potentially factoryElementB() and other factory methods.
};

} // namesapce AbstractFactoryNS


#endif // ABSTRACT_FACTORY_HPP