#include "02_strategy/context.hpp"
#include <iostream>


namespace Strategy
{

/*
** Implementation of the classic solution.
*/
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

/*
** Implementation of the function-based solution.
*/
ContextF::ContextF(std::function<void(int)>& strategy, const std::int64_t data)
  : m_strategy(strategy),
    m_data(data)
{}

void ContextF::set_strategy(std::function<void(int)>& strategy)
{
    m_strategy = strategy;
}

void ContextF::apply_strategy()
{
    std::cout << "I'm the Context. I'll apply the strategy.\n";
    m_strategy(m_data);
}

} // namespace Strategy
