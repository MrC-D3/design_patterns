#ifndef ITERATOR_INTERFACE_HPP
#define ITERATOR_INTERFACE_HPP


class IteratorInterface
{
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual void currentItem() = 0;
};

#endif