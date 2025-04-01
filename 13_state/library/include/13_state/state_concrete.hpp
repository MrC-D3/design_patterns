#ifndef STATE_CONCRETE_HPP
#define STATE_CONCRETE_HPP

#include "13_state/state_interface.hpp"
#include <memory>


namespace State
{

class StateConcrete1 : public StateInterface
{
  public:
    StateConcrete1() = default;
    StateConcrete1(std::unique_ptr<Context>&& context);
    StateConcrete1(const StateConcrete1& origin) = delete;
    StateConcrete1(StateConcrete1&& origin);

    StateConcrete1& operator=(const StateConcrete1& origin) = delete;
    StateConcrete1& operator=(StateConcrete1&& origin);

    void do_something() override;
    void do_something_else() override;
};

class StateConcrete2 : public StateInterface
{
  public:
    StateConcrete2() = default;
    StateConcrete2(std::unique_ptr<Context>&& context);
    StateConcrete2(const StateConcrete2& origin) = delete;
    StateConcrete2(StateConcrete2&& origin);

    StateConcrete2& operator=(const StateConcrete2& origin) = delete;
    StateConcrete2& operator=(StateConcrete2&& origin);

    void do_something() override;
    void do_something_else() override;
};

} // namespace State


#endif // STATE_CONCRETE_HPP