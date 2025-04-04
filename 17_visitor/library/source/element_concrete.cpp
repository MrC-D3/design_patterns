#include "17_visitor/element_concrete.hpp"
#include "17_visitor/visitor_interface.hpp"


namespace Visitor
{

void ElementConcreteA::access(const std::shared_ptr<VisitorInterface>& visitor)
{
    visitor->visit( shared_from_this() );
}

void ElementConcreteB::access(const std::shared_ptr<VisitorInterface>& visitor)
{
    visitor->visit( shared_from_this() );
}

}