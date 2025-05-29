#include "06_mediator/colleague_concrete.hpp"

#include <iostream>


namespace Mediator
{

void ColleagueConcreteA::operationA1() const
{
    m_mediator->notify("A1");
}

void ColleagueConcreteA::operationA2() const
{
    std::cout << "I'm ColleagueA. Just got ack from B.\n";
}


void ColleagueConcreteB::operationB1() const
{
    std::cout << "I'm ColleagueB. Just got notification from A.\n";

    operationB2();
}

void ColleagueConcreteB::operationB2() const
{
    m_mediator->notify("B2");
}

} // namespace Mediator
