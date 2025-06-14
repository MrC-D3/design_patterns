#include "07_memento/originator_concrete.hpp"
#include "07_memento/care_taker.hpp"


int main()
{
    using namespace Memento;

    auto myOriginator = std::make_shared<OriginatorConcrete>();
    CareTaker myCareTaker(myOriginator);

    // First set.
    myOriginator->set_state(1);

    // Second set.
    myCareTaker.backup();
    myOriginator->set_state(10);

    // Back to first set.
    myCareTaker.undo();

    // Show as test.
    myOriginator->show_state();

    return 0;
}
