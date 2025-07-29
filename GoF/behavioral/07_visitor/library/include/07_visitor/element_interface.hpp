#ifndef ELEMENT_INTERFACE_HPP
#define ELEMENT_INTERFACE_HPP

#include <memory>

#include "07_visitor/visitor_interface.hpp"


namespace Visitor
{

class VisitorInterface;

/*
** Solution 01: classic.
*/
class ElementInterface
{
  public:
    virtual ~ElementInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    // Double Dispatch step 1/2: which concrete access() is resolved at Dynamic 
    //  Binding with the V-Table.
    virtual void accept(const std::shared_ptr<VisitorInterface>& visitor) = 0;
};

/*
** Solution 03: the accept() method is defined only once in a template instead 
**  of in every derived implementation of ElementInterface.
*/
template <typename ElementC>
class ElementVisitableInterface : public ElementInterface
{
  public:
    void accept(const VisitorInterface& visitor) override
    {
        visitor.visit(static_cast<ElementC>(this));
    }
};
// Each ElementConcrete will inherit from this template not from the base class.

} // namespace Visitor


#endif