#include "abstract_hierarchy.hpp"
#include "implementation_hierarchy.hpp"

#include <memory>


int main()
{
    auto triangle =  std::make_unique<Triangle>(
      std::make_unique<Blue>()
    );

    triangle->draw();
}
