#ifndef ADAPTEE_DOG_HPP
#define ADAPTEE_DOG_HPP

#include <iostream>

class Dog_NonCompliant
{
  public:
    void tell()
    {
        std::cout << "I'm a Dog, non-compliant with the Target interface." <<
          std::endl;
    }
};

#endif
