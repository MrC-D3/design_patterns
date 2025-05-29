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
    // Default c'tors and operator= overloads, both copy and move.

    virtual std::unique_ptr<ElementInterfaceA> factoryElementA() = 0;
    // Potentially factoryElementB() and other factory methods.
};

} // namesapce AbstractFactoryNS


#endif // ABSTRACT_FACTORY_HPP