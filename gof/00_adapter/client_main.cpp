#include "adapter_dog.hpp"

#include <memory>


int main()
{
    auto my_animal = std::make_unique<Dog_Compliant>();

    my_animal->speak();

    return 0;
}
