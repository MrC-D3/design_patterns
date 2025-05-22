#ifndef ADAPTER_DOG_HPP
#define ADAPTER_DOG_HPP

#include "target_animal.hpp"
#include "adaptee_dog.hpp"


class Dog_Compliant : public Animal
{
  public:
    // Default d'tor, c'tors and operator= overloads (both copy and move).

    void speak() const override
    {
        m_dog.tell();
    }

  private:
    Dog_NonCompliant m_dog;
};


#endif
