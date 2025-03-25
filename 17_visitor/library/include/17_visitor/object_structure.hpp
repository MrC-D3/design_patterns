#ifndef OBJECT_STRUCTURE_HPP
#define OBJECT_STRUCTURE_HPP

#include "17_visitor/element_concrete.hpp"

#include <list>


namespace Visitor
{

class ObjectStructure
{
  public:
    ObjectStructure();

    std::list<ElementInterface*> get_elements();

  private:
    std::list<ElementInterface*> m_elements;
};

} // namespace Visitor

#endif // OBJECT_STRUCTURE_HPP
