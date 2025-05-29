#include "19_composite/component.hpp"


namespace CompositeNS
{

void Component::add(std::unique_ptr<Component>&& child)
{
    (void) child;
}

} // namespace CompositeNS
