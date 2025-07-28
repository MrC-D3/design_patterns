#include "15_strategy/context.hpp"
#include <iostream>


namespace Strategy
{

Context::Context(
  std::unique_ptr<StrategyInterface>&& strategy, 
  const std::int64_t data
)
  : m_strategy( std::move(strategy) ),
    m_data(data)
{}

void Context::set_strategy(std::unique_ptr<StrategyInterface>&& strategy)
{
    m_strategy = std::move( strategy );
}

void Context::apply_strategy()
{
    std::cout << "I'm the Context. I'll apply the strategy.\n";
    m_strategy->do_something(m_data);
}

} // namespace Strategy
