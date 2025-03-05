// Usage of pragma once is compiler-specific, not a C++ standard.
#ifndef ADAPTEE_DOG_HPP
#define ADAPTEE_DOG_HPP

#include <iostream>

class Dog_NonCompliant
{
  public:
    void tell() const
    {
        std::cout << "I'm a Dog, non-compliant with the Target interface." <<
          std::endl;
    }
};

#endif
