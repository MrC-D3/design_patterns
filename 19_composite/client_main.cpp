#include "19_composite/component.hpp"
#include "19_composite/leaf.hpp"
#include "19_composite/composite.hpp"


using namespace CompositeNS;

int main()
{
    Composite composite;
    Leaf leaf1;
    Composite sub_composite;
    Leaf leaf21;
    Leaf leaf22;

    composite.add(&leaf1);
    composite.add(&sub_composite);
    sub_composite.add(&leaf21);
    sub_composite.add(&leaf22);

    composite.act();

    return 0;
}