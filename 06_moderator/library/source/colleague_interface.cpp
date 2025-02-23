#include "06_moderator/colleague_interface.hpp"


void ColleagueInterface::set_moderator(ModeratorInterface* moderator)
{
    std::cout << "I'm a Colleague. Setting the moderator after the c'tor."
        << std::endl;

    m_moderator = moderator;
}
