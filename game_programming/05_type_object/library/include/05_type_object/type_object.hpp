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

    TypedObject typedObjectFactory();

    // Not private just to avoid a getter method.
    int m_id;
};

/*
** TypedObject: the class whose type is defined by an instance of TypeObject.
*/
class TypedObject
{
  public:
    ~TypedObject() = default;
    TypedObject(TypeObject& type);
    // Default c'tor and operator= overloads, both copy and move.

  private:
    TypeObject& m_type;
};

} // namespace TypeObjectNS


#endif // TYPE_OBJECT_HPP