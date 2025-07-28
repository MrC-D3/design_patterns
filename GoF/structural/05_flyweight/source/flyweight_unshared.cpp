#include "05_flyweight/flyweight_unshared.hpp"

#include <iostream>


namespace Flyweight
{

FlyweightUnshared::FlyweightUnshared(
  const std::uint64_t position, 
  const std::shared_ptr<FlyweightShared> shared_data)
  : m_position{position},
    m_shared_data{shared_data}
{
    std::cout << "I'm the FlyweightUnshared. Here the constructor.\n";
}

void FlyweightUnshared::draw(std::string& canvas) const
{
    canvas[m_position] = m_shared_data->get_shared_data();
}

} // namespace Flyweight