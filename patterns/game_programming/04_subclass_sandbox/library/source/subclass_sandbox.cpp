#include "04_subclass_sandbox/subclass_sandbox.hpp"
#include <iostream>


namespace SubclassSandboxNS
{

/*
** Base class implementation.
*/
void BaseClass::operation1()
{
    std::cout << "I'm the Base class. I'm doing an interaction with the \
      System.\n";
}

void BaseClass::operation2()
{
    std::cout << "I'm the Base class. I'm doing another interaction with the \
      System.\n";
}

/*
** Subclass-Sandbox implementation.
*/
void SubclassA::sandbox_method()
{
    std::cout << "I'm the Subclass. I'll use Base class' methods.\n";

    operation1();
    operation2();
}

// Another Subclass may use other BaseClass::operationX or use the same in a
//  different order or with different parameters.

} // namespace SubclassSandboxNS