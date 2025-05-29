#ifndef OBJECT_STRUCTURE_HPP
#define OBJECT_STRUCTURE_HPP

#include "17_visitor/element_concrete.hpp"
#include <memory>
#include <list>


namespace Visitor
{

class ObjectStructure
{
  public:
    ObjectStructure();
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    std::list<std::shared_ptr<ElementInterface>>& get_elements();

  private:
    std::list<std::shared_ptr<ElementInterface>> m_elements;
};

} // namespace Visitor


#endif // OBJECT_STRUCTURE_HPP
