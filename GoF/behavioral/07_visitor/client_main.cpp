#include "07_visitor/visitor_concrete.hpp"
#include "07_visitor/object_structure.hpp"

#include "07_visitor/visitor_interface.hpp"
#include "07_visitor/element_concrete.hpp"

#include <vector>


using namespace Visitor;

int main()
{
    // Classic solution.
    {
        ObjectStructure objectStructure;
        auto visitor = std::make_shared<VisitorConcrete1>();

        for(auto& i : objectStructure.get_elements())
        {
            i->accept(visitor);
        }
    }

    // C++17-features solution: std::variant<> and std::visit().
    {
        std::vector<ElementI17> elements;
        elements.emplace_back( ElementConcreteA{} );
        elements.emplace_back( ElementConcreteA{} );
        
        for(auto const& element : elements)
        {
            std::visit(Visitor17{}, element);
        }
    }

    return 0;
}