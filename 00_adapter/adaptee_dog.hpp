// Usage of pragma once is compiler-specific, not a C++ standard.
#ifndef ADAPTEE_DOG_HPP
#define ADAPTEE_DOG_HPP

#include <iostream>


class Dog_NonCompliant
{
  public:
    // Default d'tor, c'tors and operator= overloads (both copy and move).
    
    void tell() const
    {
        std::cout << "I'm a Dog, non-compliant with the Target interface.\n";
    }
};


#endif
