#ifndef MEDIATOR_CONCRETE_HPP
#define MEDIATOR_CONCRETE_HPP

#include "06_mediator/mediator_interface.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <iostream>
#include <memory>


namespace Mediator
{

class MediatorConcrete final : 
  public MediatorInterface, 
  // Parent class needed to create a shared_ptr from "this" pointer.
  public std::enable_shared_from_this<MediatorConcrete>
{
  public:
    MediatorConcrete(const std::shared_ptr<ColleagueConcreteA>& colleagueA,
      const std::shared_ptr<ColleagueConcreteB>& colleagueB);

    void notify(const std::string& notification) const override;

  private:
    std::shared_ptr<ColleagueConcreteA> m_colleagueA;
    std::shared_ptr<ColleagueConcreteB> m_colleagueB;
};

} // namespace Mediator


#endif // MEDIATOR_CONCRETE_HPP
