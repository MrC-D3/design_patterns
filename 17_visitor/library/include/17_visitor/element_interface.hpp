#ifndef ELEMENT_INTERFACE_HPP
#define ELEMENT_INTERFACE_HPP

#include "17_visitor/visitor_interface.hpp"


namespace Visitor
{

class VisitorInterface;

class ElementInterface
{
  public:
    virtual ~ElementInterface() = default;

    virtual void access(VisitorInterface* visitor) = 0;
};

} // namespace Visitor

#endif