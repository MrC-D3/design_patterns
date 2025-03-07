#include "08_prototype/prototype_client.hpp"


int main()
{    
    PrototypeClient::PrototypeClient client;

    auto prototypes = std::move( client.get_prototypes() );
    auto copy1 = std::move( prototypes[0]->clone() );
    auto copy2 = std::move( prototypes[1]->clone() );

    copy1->to_string();
    copy2->to_string();

    return 0;
}