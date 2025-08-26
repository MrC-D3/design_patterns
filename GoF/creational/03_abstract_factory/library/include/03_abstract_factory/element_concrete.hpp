#ifndef ELEMENT_CONCRETE_HPP
#define ELEMENT_CONCRETE_HPP

#include "03_abstract_factory/element_interface.hpp"


namespace AbstractFactoryNS
{

class ElementConcreteA1 final : public ElementInterfaceA
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    
    void doA() override;
};

// Potentially ElementConcreteA2 and other implementation of ProductA interface.

// Potentially ElementConcreteB1 and other Products' class hieararchies.

} // namespace AbtractFactoryNS


#endif // ELEMENT_CONCRETE_HPP
