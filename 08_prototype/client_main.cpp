#include "08_prototype/PrototypeConcrete.hpp"


int main()
{
    PrototypeConcrete original(1);

    PrototypeConcrete* copy = original.clone();
}