#include "07_composite/component.hpp"
#include "07_composite/leaf.hpp"
#include "07_composite/composite.hpp"


using namespace CompositeNS;

int main()
{
    Composite composite;
    auto sub_composite = std::make_unique<Composite>(); 

    sub_composite->add( std::make_unique<Leaf>() );
    sub_composite->add( std::make_unique<Leaf>() );
    composite.add( std::make_unique<Leaf>() );
    composite.add( std::move(sub_composite) );

    composite.act();

    return 0;
}