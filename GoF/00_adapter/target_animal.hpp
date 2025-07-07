#ifndef TARGET_ANIMAL_HPP
#define TARGET_ANIMAL_HPP


class Animal
{
  public:
    // Defining the destructor as virtual serves to correctly free derived-class
    //  allocated dynamically (e.g. Base* b = new Derived()): first call the
    //  derived-class' d'tor, then the base-class' d'tor.
    virtual ~Animal() noexcept = default;

    // Default c'tors and operator= overloads (both copy and move).

    virtual void speak() const = 0;
};


#endif
