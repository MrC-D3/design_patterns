#ifndef ELEMENT_INTERFACE_HPP
#define ELEMENT_INTERFACE_HPP


namespace AbstractFactoryNS
{

class ElementInterfaceA
{
  public:
    virtual ~ElementInterfaceA() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void doA() = 0;
};

// Potentially ElementInterfaceB and other Product interfaces.

} // namesapce AbstractFactoryNS


#endif // ELEMENT_INTERFACE_HPP