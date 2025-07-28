#ifndef MEDIATOR_CONCRETE_HPP
#define MEDIATOR_CONCRETE_HPP

#include "06_mediator/mediator_interface.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <memory>


namespace Mediator
{

class MediatorConcrete final : public MediatorInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // No custom c'tors, so the link Mediator->Colleague is done in join().
    void join(const std::shared_ptr<ColleagueInterface>& colleague);

    void notify(const std::string& notification) const override;

  private:
    std::shared_ptr<ColleagueConcreteA> m_colleagueA;
    std::shared_ptr<ColleagueConcreteB> m_colleagueB;
};

} // namespace Mediator


#endif // MEDIATOR_CONCRETE_HPP
