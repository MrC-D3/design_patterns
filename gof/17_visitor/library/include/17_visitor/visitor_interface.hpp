#ifndef VISITOR_INTERFACE_HPP
#define VISITOR_INTERFACE_HPP

#include <memory>
#include <iostream>


namespace Visitor
{

class ElementConcreteA;
class ElementConcreteB;

/*
** Classic solution.
*/
class VisitorInterface
{
  public:
    virtual ~VisitorInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    // Double Dispatch step 2/2: method overloading solved by Static Binding.
    // Method visit() also called accept().
    virtual void visit(const std::shared_ptr<ElementConcreteA>& elementA) = 0;
    virtual void visit(const std::shared_ptr<ElementConcreteB>& elementB) = 0;
};

/*
** C++17-features solution.
*/
class Visitor17
{
  public:
    virtual void operator()(const std::shared_ptr<ElementConcreteA>& elementA)
    {
        std::cout << "I'm the Visitor17 visiting ElementConcreteA.\n";
    }

    virtual void operator()(const std::shared_ptr<ElementConcreteB>& elementB)
    {
        std::cout << "I'm the Visitor17 visiting ElementConcreteB.\n";  
    }
};

} // namespace Visitor


#endif // VISITOR_INTERFACE_HPP