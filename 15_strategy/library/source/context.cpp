#include "15_strategy/context.hpp"


namespace Strategy
{

Context::Context(StrategyInterface* strategy, std::int64_t data)
  : m_strategy(strategy),
    m_data(data)
{}

void Context::set_strategy(StrategyInterface* strategy)
{
    m_strategy = strategy;
}

void Context::apply_strategy()
{
    m_strategy->do_something(m_data);
}

} // namespace Strategy
