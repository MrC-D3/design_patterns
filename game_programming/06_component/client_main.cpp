#include "06_component/component.hpp"


int main()
{
    using namespace ComponentNS;

    Component1 component1;
    Component2 component2;
    Container container(component1, component2);

    container.do_all();

    return 0;
}
