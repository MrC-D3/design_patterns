#include "06_mediator/mediator_concrete.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <memory>


int main()
{
    using namespace Mediator;

    // *** This part... ***
    auto colleagueA = std::make_shared<ColleagueConcreteA>();
    auto colleagueB = std::make_shared<ColleagueConcreteB>();

    MediatorConcrete mediator(colleagueA, colleagueB);
    // *** ... can be managed together with the Builder pattern. ***

    return 0 ;
    
    colleagueA->operationA1();

    return 0;
}
