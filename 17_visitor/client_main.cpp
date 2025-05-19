#include "17_visitor/visitor_concrete.hpp"
#include "17_visitor/object_structure.hpp"


using namespace Visitor;

int main()
{
    ObjectStructure objectStructure;
    auto visitor = std::make_shared<VisitorConcrete1>();

    for(auto& i : objectStructure.get_elements())
    {
        i->access(visitor);
    }

    return 0;
}