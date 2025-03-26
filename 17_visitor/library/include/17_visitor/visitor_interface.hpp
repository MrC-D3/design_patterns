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

    // TODO: give methods the same name (i.e. apply Method Overloading) for an
    //  example of Double Dispatch: result depends on the type of 2 variables.
    //  1. an ElementConcreteX must Override the virtual method access(), so a
    //   call like element_ptr->access() is resolved by Late/Dynamic Binding;
    //  2. in the Override of access(), the ElementConcreteX passes itself to
    //   the visit() method, so a call like visit(this) is solved by the
    //   compiler, that means Early/Static Binding.
    virtual void visitA(ElementConcreteA* elementA) = 0;
    virtual void visitB(ElementConcreteB* elementB) = 0;
};

} // namespace Visitor

#endif // VISITOR_INTERFACE_HPP