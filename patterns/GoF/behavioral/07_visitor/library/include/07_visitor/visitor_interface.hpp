// The Visitor design pattern allows to:
// - add functions without modifying the existing code (Open-Close Principle), 
//  so the API of the Elements to visit remains the same;
// - extract methods not-strictly-related to a class (Single Responsability 
//  Principle) from that class to the Visitor.

#ifndef VISITOR_INTERFACE_HPP
#define VISITOR_INTERFACE_HPP

#include <memory>
#include <iostream>

#include <variant>


namespace Visitor
{

class ElementConcreteA;
class ElementConcreteB;

/*
** Solution 01 (classic OO): virtual functions that abstract away compiled code.
** Bads: 
** - performance, because of the V-Tables, so scattered memory access;
** - violates the Dependency Inversion Principle because the VisitorI depends
**  on an implementation (VisitorInterface -> ElementConcrete); 
** - leads to cyclic dependency (VisitorI -> ElementC -> ElementI -> VisitorI);
** - adding new ElementC-s means to update VisitorI and all the VisitorC-s. 
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
** Solution 02 (using std::variant):
** - ElementC-s don't have a common base anymore, so no virtual functions;
** - using ElementI = std::variant<ElementC1, ..., ElementCn>;
** - VisitorC-s don't have a common base class anymore, so each VisitorC can 
**  support or not one ElementC without depending on a shared interface.
** Bads: 
** - available only from C++17;
** - long compilation time because who links the variant must link also all the
**  types behind;
** - big binary because each variant is sized as the biggest possible type.
*/
using ElementI17 = std::variant<ElementConcreteA, ElementConcreteB>;
class Visitor17
{
  public:
    // The example uses the derived classes here just to not define new classes.
    virtual void operator()(const ElementConcreteA& elementA)
    {
        std::cout << "I'm the Visitor17 visiting ElementConcreteA.\n";
    }

    virtual void operator()(const ElementConcreteB& elementB)
    {
        std::cout << "I'm the Visitor17 visiting ElementConcreteB.\n";  
    }
};

} // namespace Visitor


#endif // VISITOR_INTERFACE_HPP