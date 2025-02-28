#include "06_moderator/moderator_concrete.hpp"
#include "06_moderator/colleague_concrete.hpp"


int main()
{
    // *** This part... ***
    ColleagueConcreteA* colleagueA = new ColleagueConcreteA();
    ColleagueConcreteB* colleagueB = new ColleagueConcreteB();

    ModeratorConcrete moderator(colleagueA, colleagueB);
    // *** ... can be managed together with the Builder pattern. ***

    colleagueA->operationA1();

    return 0;
}
