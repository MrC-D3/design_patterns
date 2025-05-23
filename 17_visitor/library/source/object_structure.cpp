#include "17_visitor/object_structure.hpp"


namespace Visitor
{

ObjectStructure::ObjectStructure()
{
    m_elements.emplace_back(new ElementConcreteA());
    m_elements.emplace_back(new ElementConcreteB());
}

std::list<ElementInterface*> ObjectStructure::get_elements()
{
    return m_elements;
}

} // namespace Visitor
