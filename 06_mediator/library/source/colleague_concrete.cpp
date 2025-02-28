#include "06_moderator/colleague_concrete.hpp"


void ColleagueConcreteA::operationA1()
{
    m_moderator->notify("A1");
}

void ColleagueConcreteA::operationA2()
{
    std::cout << "I'm ColleagueA. Just got ack from B." << std::endl;
}


void ColleagueConcreteB::operationB1()
{
    std::cout << "I'm ColleagueB. Just got notification from A." <<
        std::endl;

    operationB2();
}

void ColleagueConcreteB::operationB2()
{
    m_moderator->notify("B2");
}
