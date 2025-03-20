#ifndef STRATEGY_CONCRETE_HPP
#define STRATEGY_CONCRETE_HPP

#include "15_strategy/strategy_interface.hpp"


namespace Strategy
{

class StrategyConcrete final : public StrategyInterface
{
  public:
    void do_something(std::int64_t data) override;
};

} // namespace Strategy

#endif // SRATEGY_CONCRETE_HPP