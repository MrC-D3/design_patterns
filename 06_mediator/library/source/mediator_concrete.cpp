#include "06_mediator/mediator_concrete.hpp"


namespace Mediator
{
    
MediatorConcrete::MediatorConcrete(
  const std::shared_ptr<ColleagueConcreteA>& colleagueA,
  const std::shared_ptr<ColleagueConcreteB>& colleagueB
)
  : m_colleagueA(colleagueA),
    m_colleagueB(colleagueB)
{
}

std::shared_ptr<MediatorConcrete> MediatorConcrete::constructor(
    const std::shared_ptr<ColleagueConcreteA>& colleagueA,
    const std::shared_ptr<ColleagueConcreteB>& colleagueB
  )
{
    std::shared_ptr<MediatorConcrete> instance{
        new MediatorConcrete(colleagueA, colleagueB)
    };

    instance->m_colleagueA->set_mediator( instance );
    instance->m_colleagueB->set_mediator( instance );

    return instance;
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
