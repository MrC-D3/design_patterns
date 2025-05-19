#ifndef ELEMENT_CONCRETE_HPP
#define ELEMENT_CONCRETE_HPP

#include "18_abstract_factory/element_interface.hpp"


namespace AbstractFactoryNS
{

class ElementConcreteA1 final : public ElementInterfaceA
{
  public:
    ~ElementConcreteA1() = default;
    ElementConcreteA1() = default;

    ElementConcreteA1(const ElementConcreteA1& origin) = default;
    ElementConcreteA1& operator=(const ElementConcreteA1& origin) = default;

    ElementConcreteA1(ElementConcreteA1&& origin) = default;
    ElementConcreteA1& operator=(ElementConcreteA1&& origin) = default;
    
    void doA() override;
};

// Potentially ElementConcreteA2 and other implementation of ProductA interface.

// Potentially ElementConcreteB1 and other Products' class hieararchies.

} // namespace AbtractFactoryNS

#endif // ELEMENT_CONCRETE_HPP
