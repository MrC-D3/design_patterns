#ifndef ELEMENT_INTERFACE_HPP
#define ELEMENT_INTERFACE_HPP


namespace AbstractFactoryNS
{

class ElementInterfaceA
{
  public:
    virtual ~ElementInterfaceA() = default;
    ElementInterfaceA() = default;

    ElementInterfaceA(const ElementInterfaceA& origin) = default;
    ElementInterfaceA& operator=(const ElementInterfaceA& origin) = default;

    ElementInterfaceA(ElementInterfaceA&& origin) = default;
    ElementInterfaceA& operator=(ElementInterfaceA&& origin) = default;

    virtual void doA() = 0;
};

// Potentially ElementInterfaceB and other Product interfaces.

} // namesapce AbstractFactoryNS

#endif // ELEMENT_INTERFACE_HPP