#ifndef COLLEAGUE_CONCRETE_HPP
#define COLLEAGUE_CONCRETE_HPP

#include <iostream>

#include "06_moderator/colleague_interface.hpp"


class ColleagueConcreteA : public ColleagueInterface
{
  public:
    void operationA1();

    void operationA2();
};

class ColleagueConcreteB : public ColleagueInterface
{
  public:
    void operationB1();

    void operationB2();
};

#endif
