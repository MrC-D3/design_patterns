#ifndef STRATEGY_INTERFACE_HPP
#define STRATEGY_INTERFACE_HPP

#include <cstdint>


// Also called Policy pattern.
namespace Strategy
{

class StrategyInterface
{
  public:
    virtual ~StrategyInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void do_something(const std::int64_t data) = 0;
};

} // namespace Strategy


#endif // STRATEGY_INTERFACE_HPP