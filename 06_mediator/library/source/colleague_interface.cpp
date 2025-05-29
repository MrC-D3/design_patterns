#include "06_mediator/colleague_interface.hpp"


namespace Mediator
{

void ColleagueInterface::set_mediator(
  const std::shared_ptr<MediatorInterface>& mediator)
{
    std::cout << "I'm a Colleague. Setting the mediator after the c'tor.\n";

    m_mediator = mediator;
}

} // namespace Mediator