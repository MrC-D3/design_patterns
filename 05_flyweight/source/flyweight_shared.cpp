#include "05_flyweight/flyweight_shared.hpp"

#include <iostream>


namespace Flyweight
{

FlyweightShared::FlyweightShared(const std::uint8_t& code)
    : m_character(static_cast<char>(code))
{
    std::cout << "I'm the FlyweightShared. Here the constructor." <<
        std::endl;
}

char FlyweightShared::get_shared_data() const
{
    return m_character;
}

} // namespace Flyweight