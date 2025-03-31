#ifndef ITERATOR_INTERFACE_HPP
#define ITERATOR_INTERFACE_HPP


namespace IteratorNS
{
  
template <typename Item>
class IteratorInterface
{
  public:
    // Defining a d'tor = 0 was a not a problem before,
    //  maybe because a DerivedClass object was never freed using a BaseClass*.
    // Having the d'tor =0 causes instantly a linking problem with template,
    //  because instantiating Derived<T> forces ~Base() to be instantiated, 
    //  and if it's missing, the linker will complain immediately.
    virtual ~IteratorInterface() = default;

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Item currentItem() const = 0;
};

} // namesapce IteratorNS


#endif // ITERATOR_INTERFACE_HPP