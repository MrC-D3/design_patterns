#ifndef OBSERVER_INTERFACE_HPP
#define OBSERVER_INTERFACE_HPP


namespace ObserverNS
{
  
class ObserverInterface
{
  public:
    virtual ~ObserverInterface() = default;
    
    virtual void update() = 0;
};

} // namespace Observer


#endif // OBSERVER_INTERFACE_HPP