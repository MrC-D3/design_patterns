#ifndef ELEMENT_CONCRETE_HPP
#define ELEMENT_CONCRETE_HPP

#include "17_visitor/element_interface.hpp"
#include <memory>


namespace Visitor
{

class VisitorInterface;

class ElementConcreteA final 
  : public ElementInterface, 
    public std::enable_shared_from_this<ElementConcreteA>
{
  public:
    ~ElementConcreteA() = default;
    ElementConcreteA() = default;

    ElementConcreteA(const ElementConcreteA& origin) = default;
    ElementConcreteA& operator=(const ElementConcreteA& origin) = default;

    ElementConcreteA(ElementConcreteA&& origin) = default;
    ElementConcreteA& operator=(ElementConcreteA&& origin) = default;

    void access(const std::shared_ptr<VisitorInterface>& visitor) override;
};

class ElementConcreteB final
  : public ElementInterface, 
    public std::enable_shared_from_this<ElementConcreteB>
{
  public:
    ~ElementConcreteB() = default;
    ElementConcreteB() = default;

    ElementConcreteB(const ElementConcreteB& origin) = default;
    ElementConcreteB& operator=(const ElementConcreteB& origin) = default;

    ElementConcreteB(ElementConcreteB&& origin) = default;
    ElementConcreteB& operator=(ElementConcreteB&& origin) = default;

    void access(const std::shared_ptr<VisitorInterface>& visitor) override;
};

} // namespace Visitor


#endif // ELEMENT_CONCRETE_HPP