// In this example, the logic (i.e. draw) is part of Unshared that has also a
//  pointer to Shared; so, the Client just work with Unshared.
// Alternatives are:
//  - the logic is in Shared and receives Unshared as parameter;
//  - the logic is in the client and reiceves both Shared and Unshared.
// You can also be interested only in the Shared, like in a matrix that models
//  the tiles of a floor: [[&tile1,&tile2], [&tile2, &tile1]].

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
      const std::uint8_t code, 
      const std::uint64_t position);

  private:
    std::shared_ptr<FlyweightShared> get_flyweight_shared(
      const std::uint8_t key);
    
    // Once a key is inserted, it's inheritly const, so don't specify.
    // Once a value's linked to a key, it can change, so better not const.
    std::map<std::uint8_t, std::shared_ptr<FlyweightShared>> 
      m_flyweights_shared_pool;
};

} // namespace Flyweight


#endif // FLYWEIGHT_FACTORY_HPP
