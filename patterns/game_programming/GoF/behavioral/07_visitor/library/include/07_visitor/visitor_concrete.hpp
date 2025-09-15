#ifndef VISITOR_CONCRETE_HPP
#define VISITOR_CONCRETE_HPP

#include "07_visitor/visitor_interface.hpp"


namespace Visitor
{

class VisitorConcrete1 final : public VisitorInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void visit(const std::shared_ptr<ElementConcreteA>& elementA) override;
    void visit(const std::shared_ptr<ElementConcreteB>& elementB) override;
};

} // namespace Visitor


#endif // VISITOR_CONCRETE_HPP