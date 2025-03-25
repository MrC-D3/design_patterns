#include "17_visitor/element_concrete.hpp"
#include "17_visitor/visitor_interface.hpp"


namespace Visitor
{

void ElementConcreteA::access(VisitorInterface* visitor)
{
    visitor->visitA(this);
}

void ElementConcreteB::access(VisitorInterface* visitor)
{
    visitor->visitB(this);
}

}