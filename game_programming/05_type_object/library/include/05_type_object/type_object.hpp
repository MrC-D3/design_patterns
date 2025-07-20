// Analogies with other design patterns:
// - Flyweight, since both use an object to share data between other objects;
// - State, since both delegate part of an object to another object.

#ifndef TYPE_OBJECT_HPP
#define TYPE_OBJECT_HPP


namespace TypeObjectNS
{

// Forwarding declaration.
class TypedObject;

/*
** TypeObject: the class whose instances define the types.
*/
class TypeObject
{
  public:
    ~TypeObject() = default;
    TypeObject(const int id);

    // Alternative: the client creates first the TypeObject then passes it to
    //  the TypedObject's c'tor.
    TypedObject typedObjectFactory();

    // Not private just to avoid a getter method, but kept the m_ prefix that is
    //  usually associated to private data member only.
    int m_id;
    // In game context, other data members can be: health, attack, etc.
    // Also a pointer to a parent TypeObject to emulate inheritance.
    // Also behaviors using Bytecode or Interpreter
};

/*
** TypedObject: the class whose type is defined by an instance of TypeObject.
*/
class TypedObject
{
    // Make TypeObject a friend class so it can access the private c'tor.
    // Friends are not affected by the access section (i.e. private or others).
    friend class TypeObject;

  public:
    ~TypedObject() = default;
    // Default c'tor and operator= overloads, both copy and move.

  private:
    // Private so a TypedObject can be created only by the factory method.
    TypedObject(TypeObject& type);

    // If m_type can change, you must ensure that any TypedObject data member is
    //  consistent with the new m_type; e.g. a Monster whose new type is Troll
    //  so its new health can't be over a Troll's maximum health.
    TypeObject& m_type;
};

} // namespace TypeObjectNS


#endif // TYPE_OBJECT_HPP