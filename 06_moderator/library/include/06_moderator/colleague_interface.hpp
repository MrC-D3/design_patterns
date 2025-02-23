#ifndef COLLEAGUE_INTERFACE_HPP
#define COLLEAGUE_INTERFACE_HPP

#include <iostream>

#include "06_moderator/moderator_interface.hpp"


class ColleagueInterface
{
  public:
    void set_moderator(ModeratorInterface* moderator = nullptr);

  protected:
    ModeratorInterface* m_moderator;
};


#endif
