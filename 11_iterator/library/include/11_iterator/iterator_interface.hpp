#ifndef ITERATOR_INTERFACE_HPP
#define ITERATOR_INTERFACE_HPP


namespace IteratorNS
{
  
template <typename Item>
class IteratorInterface
{
  public:
    virtual ~IteratorInterface() = 0;

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Item currentItem() const = 0;
};

} // namesapce IteratorNS


#endif // ITERATOR_INTERFACE_HPP