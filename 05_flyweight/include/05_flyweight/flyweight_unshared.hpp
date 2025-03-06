#ifndef FLYWEIGHT_UNSHARED_HPP
#define FLYWEIGHT_UNSHARED_HPP

#include "05_flyweight/flyweight_shared.hpp"

#include <cstdint>
#include <string>
#include <memory>


namespace Flyweight
{

class FlyweightUnshared
{
  public:
    FlyweightUnshared(const uint64_t& position, 
      const std::shared_ptr<FlyweightShared>& shared_data);

    void draw(std::string& canvas) const;

  private:
    std::uint64_t m_position{0};
    std::shared_ptr<FlyweightShared> m_shared_data;
};

} // namespace Flyweight


#endif // FLYWEIGHT_UNSHARED_HPP
