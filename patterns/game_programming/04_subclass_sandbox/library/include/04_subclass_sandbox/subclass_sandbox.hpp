// Role reversal of the Template Method pattern where a method A is implemented
//  using methods B1, B2, etc. defined by the derived class; here, the methods 
//  Bx are defined in the base class and each derived class decides how to use 
//  them in A.
// Another analogy is with the Facade pattern: here, the base class works as a 
//  facade for the derived classes, so that they don't need to know what's
//  outside of their class hierarchy and they only need to include the base
//  class' header.

// Problem: what if the base class needs to initialize some private data member?
//  It's not nice to make this initialization visible from every derived class.

#ifndef SUBCLASS_SANDBOX_HPP
#define SUBCLASS_SANDBOX_HPP


namespace SubclassSandboxNS
{
class BaseClass
{
  public:
    virtual ~BaseClass() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void sandbox_method() = 0;

  protected:
    void operation1();
    void operation2();
    // Potentially other operationX that interact with the rest of the system.
};

class SubclassA : public BaseClass
{
  public:
    void sandbox_method() override;
};

} // namespace SubclassSandboxNS


#endif // SUBCLASS_SANDBOX_HPP