#ifndef OBSERVER_INTERFACE_HPP
#define OBSERVER_INTERFACE_HPP


namespace ObserverNS
{
  
class ObserverInterface
{
  public:
    virtual ~ObserverInterface() = default;
    
    // Method needed because you can't call shared_from_this() in the d'tor.
    // Not const or shared_from_this<>() returns a shared_ptr<const Observer>.
    virtual void attach() = 0;

    virtual void update() = 0;
};

} // namespace Observer


#endif // OBSERVER_INTERFACE_HPP