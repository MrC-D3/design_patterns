#include "05_type_object/type_object.hpp"
#include <iostream>


namespace TypeObjectNS
{

/*
** TypeObject class implementation.
*/
TypeObject::TypeObject(const int id)
: m_id{id}
{}

TypedObject TypeObject::typedObjectFactory()
{
    return {*this};
}

/*
** TypedObject class implementation.
*/
TypedObject::TypedObject(TypeObject& type)
: m_type{type}
{
    std::cout << "I'm a TypedObject of type: " << m_type.m_id << ".\n";
}

} // namespace TypeObjectNS
