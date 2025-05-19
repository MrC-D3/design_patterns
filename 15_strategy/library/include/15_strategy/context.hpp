#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "15_strategy/strategy_interface.hpp"
#include <memory>


namespace Strategy
{

class Context
{
  public:
    ~Context() = default;
    explicit Context(
      std::unique_ptr<StrategyInterface>&& strategy = nullptr, 
      const std::int64_t& data = 0);

    Context(const Context& origin) = delete;
    Context& operator=(const Context& origin) = delete;

    Context(Context&& origin) = default;
    Context& operator=(Context&& origin) = default;

    void set_strategy(std::unique_ptr<StrategyInterface>&& strategy);

    void apply_strategy();

  protected:
    std::unique_ptr<StrategyInterface> m_strategy;
    std::int64_t m_data;
};

} // namespace Strategy


#endif // CONTEXT_HPP