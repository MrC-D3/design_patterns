#ifndef MEDIATOR_CONCRETE_HPP
#define MEDIATOR_CONCRETE_HPP

#include "06_mediator/mediator_interface.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <iostream>
#include <memory>


namespace Mediator
{

class MediatorConcrete final : public MediatorInterface
{
  public:
    void notify(const std::string& notification) const override;

    static std::shared_ptr<MediatorConcrete> constructor(
      const std::shared_ptr<ColleagueConcreteA>& colleagueA,
      const std::shared_ptr<ColleagueConcreteB>& colleagueB
    );

  private:
    MediatorConcrete(const std::shared_ptr<ColleagueConcreteA>& colleagueA,
      const std::shared_ptr<ColleagueConcreteB>& colleagueB);

    std::shared_ptr<ColleagueConcreteA> m_colleagueA;
    std::shared_ptr<ColleagueConcreteB> m_colleagueB;
};

} // namespace Mediator


#endif // MEDIATOR_CONCRETE_HPP
