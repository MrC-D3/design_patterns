#include "08_prototype/prototype_client.hpp"


int main()
{
    PrototypeClient client;
    auto prototypes = client.get_prototypes();

    PrototypeInterface* copy1 = prototypes[0]->clone();
    PrototypeInterface* copy2 = prototypes[0]->clone();

    copy1->to_string();
    copy2->to_string();

    return 0;
}