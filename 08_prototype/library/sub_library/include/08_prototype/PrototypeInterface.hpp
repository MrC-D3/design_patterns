#ifndef PROTOTYPE_INTERFACE_HPP
#define PROTOTYPE_INTERFACE_HPP


class PrototypeInterface
{
  public:
    virtual PrototypeInterface* clone() = 0;

    virtual void to_string() = 0;
};

#endif