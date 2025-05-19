#ifndef VISITOR_INTERFACE_HPP
#define VISITOR_INTERFACE_HPP

#include <memory>


namespace Visitor
{

class ElementConcreteA;
class ElementConcreteB;

class VisitorInterface
{
  public:
    virtual ~VisitorInterface() = default;
    VisitorInterface() = default;

    VisitorInterface(const VisitorInterface& origin) = default;
    VisitorInterface& operator=(const VisitorInterface& origin) = default;

    VisitorInterface(VisitorInterface&& origin) = default;
    VisitorInterface& operator=(VisitorInterface&& origin) = default;

    // Double Dispatch phase 2: Method overloading solved at Early/Static 
    //  Binding by the compiler.
    virtual void visit(const std::shared_ptr<ElementConcreteA>& elementA) = 0;
    virtual void visit(const std::shared_ptr<ElementConcreteB>& elementB) = 0;
};

} // namespace Visitor

#endif // VISITOR_INTERFACE_HPP