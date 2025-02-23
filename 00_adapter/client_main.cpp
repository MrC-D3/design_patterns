#include "target_animal.hpp"
#include "adapter_dog.hpp"

int main()
{
    Animal* my_animal = new Dog_Compliant();

    my_animal->speak();

    return 0;
}
