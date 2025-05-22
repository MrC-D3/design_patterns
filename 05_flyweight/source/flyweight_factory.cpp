#include <iostream>

#include "05_flyweight/flyweight_factory.hpp"


namespace Flyweight
{

std::unique_ptr<FlyweightUnshared> FlyweightFactory::create_flyweight(
  const std::uint8_t code, const std::uint64_t position)
{
    auto shared_data = get_flyweight_shared(code);

    return std::make_unique<FlyweightUnshared>(position, shared_data);
}

std::shared_ptr<FlyweightShared> FlyweightFactory::get_flyweight_shared(
  const uint8_t key)
{
    std::cout << "I'm the FlyweightFactory. I have the shared in the pool?\n";

    auto iterator = m_flyweights_shared_pool.find(key);
    if(iterator == m_flyweights_shared_pool.end())
    {
        auto return_value = std::make_shared<FlyweightShared>(key);
        // Emplace more efficient than Insert: avoid creation of a temp object.
        m_flyweights_shared_pool.emplace(key, return_value);

        return return_value;
    }

    // Avoid calling again the expensive lookup function on the map.
    return iterator->second;
}

} // namespace Flyweight