#ifndef VISITOR_CONCRETE_HPP
#define VISITOR_CONCRETE_HPP

#include "17_visitor/visitor_interface.hpp"


namespace Visitor
{

class VisitorConcrete1 final : public VisitorInterface
{
  public:
    ~VisitorConcrete1() = default;
    VisitorConcrete1() = default;

    VisitorConcrete1(const VisitorConcrete1& origin) = default;
    VisitorConcrete1& operator=(const VisitorConcrete1& origin) = default;

    VisitorConcrete1(VisitorConcrete1&& origin) = default;
    VisitorConcrete1& operator=(VisitorConcrete1&& origin) = default;

    void visit(const std::shared_ptr<ElementConcreteA>& elementA) override;
    void visit(const std::shared_ptr<ElementConcreteB>& elementB) override;
};

} // namespace Visitor


#endif // VISITOR_CONCRETE_HPP