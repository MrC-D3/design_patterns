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
    ~ObjectStructure() = default;
    ObjectStructure();

    ObjectStructure(const ObjectStructure& origin) = delete;
    ObjectStructure& operator=(const ObjectStructure& origin) = delete;

    ObjectStructure(ObjectStructure&& origin) = default;
    ObjectStructure& operator=(ObjectStructure&& origin) = default;

    std::list<std::shared_ptr<ElementInterface>>& get_elements();

  private:
    std::list<std::shared_ptr<ElementInterface>> m_elements;
};

} // namespace Visitor

#endif // OBJECT_STRUCTURE_HPP
