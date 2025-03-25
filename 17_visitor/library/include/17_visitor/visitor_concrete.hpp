#ifndef VISITOR_CONCRETE_HPP
#define VISITOR_CONCRETE_HPP

#include "17_visitor/visitor_interface.hpp"


namespace Visitor
{

class VisitorConcrete1 : public VisitorInterface
{
  public:
    void visitA(ElementConcreteA* elementA) override;

    void visitB(ElementConcreteB* elementB) override;
};

} // namespace Visitor


#endif // VISITOR_CONCRETE_HPP