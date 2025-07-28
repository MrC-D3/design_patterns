// The Component pattern helps to decouple code that belongs to different 
//  domains.

#ifndef COMPONENT_HPP
#define COMPONENT_HPP


namespace ComponentNS
{

/*
** Component1 for one domain, e.g. PlayerInputComponent.
*/
class Component1
{
  public:
    // Default d'tor, c'tor and operator= overloads, both copy and move.

    void do_something();
};

/*
** Component2 for another domain, e.g. PhysicsComponent.
*/
class Component2
{
  public:
    // Default d'tor, c'tor and operator= overloads, both copy and move.

    void do_something();
};

// Potentially Component3 (e.g. GraphicsComponent) and so on.

/*
** Container class doesn't need to have a reference to each possible Component.
**  For example, there can be an entity of a game that doesn't need PlayerInput.
*/
class Container
{
  public:
    // If ComponentX doesn't store a state, it can be reused somewhere else.
    //  That case would be similar to a Strategy pattern.
    Container(Component1& component1, Component2& component2);
    // Default d'tor, c'tor and operator= overloads, both copy and move.

    void do_all(); 

  private:
    Component1 m_component1;
    Component2 m_component2;
};

} // namespace ComponentNS


#endif // COMPONENT_HPP