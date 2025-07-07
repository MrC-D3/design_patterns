#ifndef STRATEGY_CONCRETE_HPP
#define STRATEGY_CONCRETE_HPP

#include "15_strategy/strategy_interface.hpp"


namespace Strategy
{

class StrategyConcrete final : public StrategyInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void do_something(const std::int64_t data) override;
};

} // namespace Strategy


#endif // SRATEGY_CONCRETE_HPP