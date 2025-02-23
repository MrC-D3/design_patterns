#ifndef ADAPTER_DOG_HPP
#define ADAPTER_DOG_HPP

#include "target_animal.hpp"
#include "adaptee_dog.hpp"

class Dog_Compliant : public Animal
{
  public:
    void speak() override
    {
        m_dog.tell();
    }

  private:
    Dog_NonCompliant m_dog;
};

#endif
