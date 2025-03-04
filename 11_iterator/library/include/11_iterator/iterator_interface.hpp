#ifndef ITERATOR_INTERFACE_HPP
#define ITERATOR_INTERFACE_HPP


template <typename Item>
class IteratorInterface
{
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Item currentItem() = 0;
};

#endif