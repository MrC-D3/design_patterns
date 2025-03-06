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
    auto this_shared = shared_from_this();
        return ;

    colleagueA->set_mediator( this_shared );
    colleagueB->set_mediator( this_shared );
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
