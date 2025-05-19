#ifndef STRATEGY_CONCRETE_HPP
#define STRATEGY_CONCRETE_HPP

#include "15_strategy/strategy_interface.hpp"


namespace Strategy
{

class StrategyConcrete final : public StrategyInterface
{
  public:
    ~StrategyConcrete() = default;
    StrategyConcrete() = default;

    StrategyConcrete(const StrategyConcrete& origin) = default;
    StrategyConcrete& operator=(const StrategyConcrete& origin) = default;

    StrategyConcrete(StrategyConcrete&& origin) = default;
    StrategyConcrete& operator=(StrategyConcrete&& origin) = default;

    void do_something(const std::int64_t& data) override;
};

} // namespace Strategy

#endif // SRATEGY_CONCRETE_HPP