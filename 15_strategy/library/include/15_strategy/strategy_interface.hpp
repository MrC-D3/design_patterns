#ifndef STRATEGY_INTERFACE_HPP
#define STRATEGY_INTERFACE_HPP

#include <cstdint>


namespace Strategy
{

class StrategyInterface
{
  public:
    virtual ~StrategyInterface() = default;

    virtual void do_something(std::int64_t data) = 0;
};

} // namespace Strategy


#endif // STRATEGY_INTERFACE_HPP