#ifndef VISITOR_INTERFACE_HPP
#define VISITOR_INTERFACE_HPP

#include "17_visitor/element_concrete.hpp"


namespace Visitor
{

class ElementConcreteA;
class ElementConcreteB;

class VisitorInterface
{
  public:
    virtual ~VisitorInterface() = default;

    virtual void visitA(ElementConcreteA* elementA) = 0;
    virtual void visitB(ElementConcreteB* elementB) = 0;
};

} // namespace Visitor

#endif // VISITOR_INTERFACE_HPP