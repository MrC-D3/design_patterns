#include "07_visitor/element_concrete.hpp"
#include "07_visitor/visitor_interface.hpp"


namespace Visitor
{

/*
** ElementConcreteA implementation.
*/
void ElementConcreteA::accept(const std::shared_ptr<VisitorInterface>& visitor)
{
    visitor->visit( shared_from_this() );
}

/*
** ElementConcreteB implementation.
*/
void ElementConcreteB::accept(const std::shared_ptr<VisitorInterface>& visitor)
{
    visitor->visit( shared_from_this() );
}

} // namespace Visitor