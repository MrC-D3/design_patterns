#include "04_subclass_sandbox/subclass_sandbox.hpp"


int main()
{
    using namespace SubclassSandboxNS;

    SubclassA subclass;

    subclass.sandbox_method();

    return 0;
}