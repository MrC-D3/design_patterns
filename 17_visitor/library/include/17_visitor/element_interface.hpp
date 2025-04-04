#ifndef ELEMENT_INTERFACE_HPP
#define ELEMENT_INTERFACE_HPP

#include <memory>


namespace Visitor
{

class VisitorInterface;

class ElementInterface
{
  public:
    virtual ~ElementInterface() = default;
    ElementInterface() = default;

    ElementInterface(const ElementInterface& origin) = default;
    ElementInterface& operator=(const ElementInterface& origin) = default;

    ElementInterface(ElementInterface&& origin) = default;
    ElementInterface& operator=(ElementInterface&& origin) = default;

    // Double Dispatch phase 1: which concrete access() resolved at Late/Dynamic 
    //  Binding with the V-Table.
    virtual void access(const std::shared_ptr<VisitorInterface>& visitor) = 0;
};

} // namespace Visitor

#endif