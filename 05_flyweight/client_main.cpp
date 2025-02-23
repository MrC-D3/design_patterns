#include <array>
#include <string>

#include "05_flyweight/flyweight_factory.hpp"


int main()
{
    FlyweightFactory myFactory;
    std::array<FlyweightUnshared*, 5> myString;

    // Decimal code for M: 77.
    myString[0] = myFactory.create_flyweight(77, 0);
    myString[1] = myFactory.create_flyweight(77, 2);
    myString[2] = myFactory.create_flyweight(77, 3);
    // Decimal code for A: 65.
    myString[3] = myFactory.create_flyweight(65, 1);
    myString[4] = myFactory.create_flyweight(65, 4);

    std::string canvas;
    canvas.resize(5);
    for(uint8_t i = 0; i < 5u; i++)
    {
        myString[i]->draw(canvas);
    }

    std::cout << "Result: " << canvas << std::endl;

    return 0;
}
