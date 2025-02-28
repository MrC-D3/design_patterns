#include "06_moderator/moderator_concrete.hpp"


ModeratorConcrete::ModeratorConcrete(ColleagueConcreteA* colleagueA,
    ColleagueConcreteB* colleagueB)
    : m_colleagueA(colleagueA),
      m_colleagueB(colleagueB)
{
    colleagueA->set_moderator(this);
    colleagueB->set_moderator(this);
}

void ModeratorConcrete::notify(std::string notification)
{
    if(notification == "A1")
    {
        m_colleagueB->operationB1();
    }
    else if(notification == "B2")
    {
        m_colleagueA->operationA2();
    }
}
