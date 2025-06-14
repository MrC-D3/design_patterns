#include "17_visitor/visitor_concrete.hpp"
#include "17_visitor/object_structure.hpp"

#include "17_visitor/visitor_interface.hpp"
#include "17_visitor/element_concrete.hpp"

#include <variant>


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
        std::variant<
          std::shared_ptr<ElementConcreteA>, 
          std::shared_ptr<ElementConcreteB>
        > element = std::make_shared<ElementConcreteA>();
        Visitor17 visitor;
        
        std::visit(visitor, element);
    }

    return 0;
}