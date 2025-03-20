#ifndef CONTEXT_INTERFACE_HPP
#define CONTEXT_INTERFACE_HPP

#include "15_strategy/strategy_interface.hpp"


namespace Strategy
{

class ContextInterface
{
  public:
    ContextInterface(StrategyInterface* strategy = nullptr)
      : m_strategy(strategy)
    {}

    virtual ~ContextInterface() = default;

    void set_strategy(StrategyInterface* strategy)
    {
        m_strategy = strategy;
    }

    void apply_strategy()
    {
        m_strategy->do_something(m_data);
    }

  protected:
    StrategyInterface* m_strategy;
    std::int64_t m_data;
};

} // namespace Strategy


#endif // CONTEXT_INTERFAFCE_HPP