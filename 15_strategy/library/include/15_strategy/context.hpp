#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "15_strategy/strategy_interface.hpp"


namespace Strategy
{

class Context
{
  public:
    Context(StrategyInterface* strategy = nullptr, std::int64_t data = 0);

    void set_strategy(StrategyInterface* strategy);

    void apply_strategy();

  protected:
    StrategyInterface* m_strategy;
    std::int64_t m_data;
};

} // namespace Strategy


#endif // CONTEXT_HPP