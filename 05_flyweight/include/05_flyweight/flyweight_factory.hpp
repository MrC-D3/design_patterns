#ifndef FLYWEIGHT_FACTORY_HPP
#define FLYWEIGHT_FACTORY_HPP

#include <map>
#include <vector>

#include "05_flyweight/flyweight_shared.hpp"
#include "05_flyweight/flyweight_unshared.hpp"


class FlyweightFactory
{
  public:
    FlyweightUnshared* create_flyweight(uint8_t code, uint64_t position);

  private:
    FlyweightShared* get_flyweight_shared(uint8_t key);

    std::map<int, FlyweightShared*> m_flyweights_shared_pool;
};

#endif
