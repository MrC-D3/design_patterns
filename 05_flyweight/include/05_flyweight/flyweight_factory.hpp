// Usually, the behavior of the original object remains in the flyweight class.
// In this case, whoever calls a flyweight’s method must also pass appropriate
// bits of the extrinsic state into the method’s parameters. On the other hand,
// the behavior can be moved to the context class, which would use the linked
// flyweight merely as a data object.

#ifndef FLYWEIGHT_FACTORY_HPP
#define FLYWEIGHT_FACTORY_HPP

#include "05_flyweight/flyweight_shared.hpp"
#include "05_flyweight/flyweight_unshared.hpp"

#include <map>
#include <memory>
#include <cstdint>


namespace Flyweight
{

class FlyweightFactory
{
  public:
    std::unique_ptr<FlyweightUnshared> create_flyweight(
      const std::uint8_t& code, 
      const std::uint64_t& position);

  private:
    std::shared_ptr<FlyweightShared> get_flyweight_shared(
      const std::uint8_t& key);
    
    // Once a key is inserted, it's inheritly const, so don't specify.
    // Once a value's linked to a key, it can change, so better not const.
    std::map<std::uint8_t, std::shared_ptr<FlyweightShared>> 
      m_flyweights_shared_pool;
};

} // namespace Flyweight


#endif // FLYWEIGHT_FACTORY_HPP
