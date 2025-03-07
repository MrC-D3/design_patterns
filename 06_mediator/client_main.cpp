#include "06_mediator/mediator_concrete.hpp"
#include "06_mediator/colleague_concrete.hpp"

#include <memory>


int main()
{
    using namespace Mediator;

    // *** This part... ***
    auto colleagueA = std::make_shared<ColleagueConcreteA>();
    auto colleagueB = std::make_shared<ColleagueConcreteB>();

    auto mediator = MediatorConcrete::constructor(colleagueA, colleagueB);
    // *** ... can be all managed using the Builder pattern. ***
    
    colleagueA->operationA1();

    return 0;
}
