#include "07_visitor/object_structure.hpp"


namespace Visitor
{

ObjectStructure::ObjectStructure()
{
    m_elements.emplace_back( std::make_shared<ElementConcreteA>() );
    m_elements.emplace_back( std::make_shared<ElementConcreteB>() );
}

std::list<std::shared_ptr<ElementInterface>>& ObjectStructure::get_elements()
{
    return m_elements;
}

} // namespace Visitor
