#ifndef MODERATOR_CONCRETE_HPP
#define MODERATOR_CONCRETE_HPP

#include <iostream>

#include "06_moderator/moderator_interface.hpp"
#include "06_moderator/colleague_concrete.hpp"


class ModeratorConcrete : public ModeratorInterface
{
  public:
    ModeratorConcrete(ColleagueConcreteA* colleagueA = nullptr,
      ColleagueConcreteB* colleagueB = nullptr);

    void notify(std::string notification) override;

  private:
    ColleagueConcreteA* m_colleagueA = nullptr;
    ColleagueConcreteB* m_colleagueB = nullptr;
};

#endif
