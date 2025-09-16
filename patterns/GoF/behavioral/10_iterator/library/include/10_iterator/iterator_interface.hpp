#ifndef ITERATOR_INTERFACE_HPP
#define ITERATOR_INTERFACE_HPP


namespace IteratorNS
{
  
template <typename Item>
class IteratorInterface
{
  public:
    virtual ~IteratorInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Item currentItem() const = 0;
};

// Alternative: use boost/iterator/iterator_facade.hpp library.

} // namesapce IteratorNS


#endif // ITERATOR_INTERFACE_HPP