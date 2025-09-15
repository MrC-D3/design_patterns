#include "05_type_object/type_object.hpp"


int main()
{
    using namespace TypeObjectNS;

    TypeObject type1{1};
    auto typedObject1 = type1.typedObjectFactory();

    return 0;
}