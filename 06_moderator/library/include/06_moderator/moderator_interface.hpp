#ifndef MODERATOR_INTERFACE_HPP
#define MODERATOR_INTERFACE_HPP

#include <string>


class ModeratorInterface
{
  public:
    virtual void notify(std::string notification) = 0;
};

#endif
