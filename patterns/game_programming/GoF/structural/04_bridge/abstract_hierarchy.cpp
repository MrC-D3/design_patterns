#include "abstract_hierarchy.hpp"


/*
** AbstractClass::ImplementationClass declaration and definition.
*/
class AbstractClass::ImplementationClass
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // This can potentially be a method that would be private in AbstractClass.
    // This way you avoid exposing even the signature.
    void actually_do_something(const AbstractClass& interface)
    {
        std::cout << "I'm ImplementationClass. Actually doing something.\n";
        std::cout << "Data: " << interface.m_data << std::endl;
    }
};

/*
** AbstractClass definition.
*/
// Since ImplementationClass is not exposed, user can't pass an instance of it.
//  If possible multiple ImplementationClass, you can pass an enum value.
AbstractClass::AbstractClass(const int data)
: m_data{data}, m_pimpl_bridge{new ImplementationClass}
{}

void AbstractClass::do_something()
{
    m_pimpl_bridge->actually_do_something(*this);
}