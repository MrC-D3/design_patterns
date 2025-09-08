#include "06_mediator/mediator_concrete.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <memory>


// Do I really need (smart) pointers or I can use references?
int main()
{
    using namespace Mediator;

    // *** To avoid having Colleague-s without a Mediator, this part... ***
    auto mediator = std::make_shared<MediatorConcrete>();

    auto colleagueA = std::make_shared<ColleagueConcreteA>();
    auto colleagueB = std::make_shared<ColleagueConcreteB>();

    mediator->join(colleagueA);
    mediator->join(colleagueB);
    // *** ... can be all managed using the Builder pattern. ***
    
    colleagueA->operationA1();

    return 0;
}
