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
    // Default c'tors and operator= overloads, both copy and move.

    // Double Dispatch step 1/2: which concrete access() is resolved at Dynamic 
    //  Binding with the V-Table.
    virtual void accept(const std::shared_ptr<VisitorInterface>& visitor) = 0;
};

} // namespace Visitor


#endif