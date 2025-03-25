#ifndef OBJECT_STRUCTURE_HPP
#define OBJECT_STRUCTURE_HPP

#include "17_visitor/element_concrete.hpp"

#include <list>


namespace Visitor
{

class ObjectStructure
{
  public:
    ObjectStructure()
    {
        m_elements.emplace_back(ElementConcreteA());
        m_elements.emplace_back(ElementConcreteB());
    }

    std::list<ElementInterface*> get_elements()
    {
        return m_elements;
    }

  private:
    std::list<ElementInterface*> m_elements;
};

} // namespace Visitor

#endif // OBJECT_STRUCTURE_HPP
