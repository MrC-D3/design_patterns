#include "06_mediator/mediator_concrete.hpp"

#include <iostream>


namespace Mediator
{

void MediatorConcrete::join(
  const std::shared_ptr<ColleagueInterface>& colleague)
{
    auto colleagueA = std::dynamic_pointer_cast<ColleagueConcreteA>(
      colleague);
    if(colleagueA)
    {
        m_colleagueA = colleagueA;
    }
    else
    {
        auto colleagueB = std::dynamic_pointer_cast<ColleagueConcreteB>(
        colleague);
        if(colleagueB)
        {
            m_colleagueB = colleagueB;
        }
        else
        {
            return;
        }
    }

    colleague->set_mediator(shared_from_this());
}

void MediatorConcrete::notify(const std::string& notification) const
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

} // namespace Mediator
