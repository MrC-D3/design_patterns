#ifndef MEMENTO_INTERFACE_HPP
#define MEMENTO_INTERFACE_HPP


namespace Memento
{

class MementoInterface
{
  public:
    virtual void restore() const = 0;
};

} // namespace Memento

#endif // MEMENTO_INTERFACE_HPP
