#ifndef ELEMENT_CONCRETE_HPP
#define ELEMENT_CONCRETE_HPP

#include "17_visitor/element_interface.hpp"
#include <memory>


namespace Visitor
{

class VisitorInterface;

/*
** ElementConcreteA declarations.
*/
class ElementConcreteA final 
  : public ElementInterface, 
    public std::enable_shared_from_this<ElementConcreteA>
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void accept(const std::shared_ptr<VisitorInterface>& visitor) override;
};

/*
** ElementConcreteB declarations.
*/
class ElementConcreteB final
  : public ElementInterface, 
    public std::enable_shared_from_this<ElementConcreteB>
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void accept(const std::shared_ptr<VisitorInterface>& visitor) override;
};

} // namespace Visitor


#endif // ELEMENT_CONCRETE_HPP