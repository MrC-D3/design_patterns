#include "17_visitor/visitor_concrete.hpp"

#include <iostream>


namespace Visitor
{

void VisitorConcrete1::visitA(ElementConcreteA* elementA)
{
    std::cout << "I'm the VisitorConcrete1 visiting ElementConcreteA." << 
        std::endl;
}

void VisitorConcrete1::visitB(ElementConcreteB* elementB)
{
    std::cout << "I'm the VisitorConcrete1 visiting ElementConcreteB." << 
        std::endl;
}

} // namespace Visitor