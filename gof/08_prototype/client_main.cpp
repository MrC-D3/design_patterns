#include "08_prototype/prototype_client.hpp"


int main()
{    
    PrototypeClient::PrototypeClient client;

    // Keyword "auto" becomes std::array<...>, "const" and "&" must be added.
    const auto& prototypes = client.get_prototypes();
    auto copy1 = std::move( prototypes[0]->clone() );
    auto copy2 = std::move( prototypes[1]->clone() );

    copy1->to_string();
    copy2->to_string();

    // Call to get_prototypes() can be repeated.
    const auto& prototypes2 = client.get_prototypes();
    prototypes2[0]->to_string();

    return 0;
}