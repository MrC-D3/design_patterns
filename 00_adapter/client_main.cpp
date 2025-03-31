#include "target_animal.hpp"
#include "adapter_dog.hpp"

#include <memory>


int main()
{
    std::unique_ptr<Animal> my_animal = std::make_unique<Dog_Compliant>();

    my_animal->speak();

    return 0;
}
