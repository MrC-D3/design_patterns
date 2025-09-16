#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "02_strategy/strategy_interface.hpp"

#include <memory>
#include <iostream>
#include <functional>


namespace Strategy
{

/*
** Classic solution.
*/
class Context
{
  public:
    // Default c'tor and operator= overloads, both copy and move.

    explicit Context(
      std::unique_ptr<StrategyInterface>&& strategy = nullptr, 
      const std::int64_t data = 0);

    void set_strategy(std::unique_ptr<StrategyInterface>&& strategy);

    void apply_strategy();

  private:
    std::unique_ptr<StrategyInterface> m_strategy;
    std::int64_t m_data;
};

/*
** Function-based solution: no need of a Strategy class hierarchy.
*/
class ContextF
{
  public:
    // Default c'tor and operator= overloads, both copy and move.

    explicit ContextF(
      std::function<void(int)>& strategy, 
      const std::int64_t data = 0);

    void set_strategy(std::function<void(int)>& strategy);

    void apply_strategy();

  private:
    std::function<void(int)> m_strategy;
    std::int64_t m_data;
};

/*
** Template solution: no pure-Strategy pattern because you can't choose the 
**  Strategy at run-time, but better performance (because no v-table).
*/
template <typename StrategyT>
class ContextT
{
    static_assert(
      std::is_base_of<StrategyInterface, StrategyT>::value, 
      "StrategyT must be a StrategyInterface.");

  public:
    // Default c'tor and operator= overloads, both copy and move.

    explicit ContextT(const std::int64_t data = 0)
    : m_data{ data }
    {}

    void apply_strategy()
    {
        std::cout << "I'm the ContextT. I'll apply the StrategyT.\n";
        m_strategy.do_something(m_data);
    }

  private:
    StrategyT m_strategy;
    std::int64_t m_data;
};

} // namespace Strategy


#endif // CONTEXT_HPP