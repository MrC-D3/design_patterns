#include "05_flyweight/flyweight_factory.hpp"

#include <array>
#include <string>
#include <iostream>
#include <cstdint>


int main()
{
    using namespace Flyweight;
    constexpr std::uint64_t array_size = 5U;
    constexpr std::uint8_t ascii_m = 77U;
    constexpr std::uint8_t ascii_a = 65U;

    FlyweightFactory myFactory;
    std::array<std::unique_ptr<FlyweightUnshared>, array_size> myString;

    // Decimal code for M: 77.
    myString[0] = myFactory.create_flyweight(ascii_m, 0U);
    myString[1] = myFactory.create_flyweight(ascii_m, 2U);
    myString[2] = myFactory.create_flyweight(ascii_m, 3U);
    // Decimal code for A: 65.
    myString[3] = myFactory.create_flyweight(ascii_a, 1U);
    myString[4] = myFactory.create_flyweight(ascii_a, 4U);

    // Declare and initialize the std::string directly.
    std::string canvas(array_size, ' ');

    // Modern C++ loop.
    for(const auto& flyweight : myString)
    {
        flyweight->draw(canvas);
    }

    std::cout << "Result: " << canvas << std::endl;

    return 0;
}
