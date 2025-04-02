#ifndef STRATEGY_INTERFACE_HPP
#define STRATEGY_INTERFACE_HPP

#include <cstdint>


namespace Strategy
{

class StrategyInterface
{
  public:
    virtual ~StrategyInterface() = default;
    StrategyInterface() = default;

    StrategyInterface(const StrategyInterface& origin) = default;
    StrategyInterface& operator=(StrategyInterface& origin) = default;

    StrategyInterface(StrategyInterface&& origin) = default;
    StrategyInterface& operator=(StrategyInterface&& origin) = default;

    virtual void do_something(const std::int64_t& data) = 0;
};

} // namespace Strategy


#endif // STRATEGY_INTERFACE_HPP