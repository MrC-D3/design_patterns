#ifndef ELEMENT_CONCRETE_HPP
#define ELEMENT_CONCRETE_HPP

#include "17_visitor/element_interface.hpp"


namespace Visitor
{

class VisitorInterface;

class ElementConcreteA : public ElementInterface
{
  public:
    void access(VisitorInterface* visitor) override;
};

class ElementConcreteB : public ElementInterface
{
  public:
    void access(VisitorInterface* visitor) override;
};

} // namespace Visitor


#endif // ELEMENT_CONCRETE_HPP