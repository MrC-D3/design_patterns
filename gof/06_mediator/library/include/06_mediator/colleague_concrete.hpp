#ifndef COLLEAGUE_CONCRETE_HPP
#define COLLEAGUE_CONCRETE_HPP

#include "06_mediator/colleague_interface.hpp"


namespace Mediator
{

class ColleagueConcreteA final : public ColleagueInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void operationA1() const;

    void operationA2() const;
};

class ColleagueConcreteB final : public ColleagueInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void operationB1() const;

    void operationB2() const;
};

} // namespace Mediator


#endif
