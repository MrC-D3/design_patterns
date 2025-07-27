#include "11_object_pool/object_pool.hpp"

#include <iostream>


namespace ObjectPoolNS
{

/*
** Object implementation.
*/
void Object::init(const int data)
{
    m_data = data;
}

bool Object::do_something()
{
    std::cout << "I'm an Object. Doing something like update() with data: " << 
      m_data << ".\n" ;

    // Say the object's done with its work.
    return true;
}

/*
** ObjectPool implementation.
*/
void ObjectPool::allocate(const int data)
{
    m_objects[m_allocated_count].init(data);
    m_allocated_count += 1;
}

void ObjectPool::all_do_something()
{
    // Unary operator '+' to cast to treat uint8_t as int not as char. 
    std::cout << "I'm the Pool. Processing " << +m_allocated_count << 
      " objects.\n";

    for(uint8_t i = 0; i < m_allocated_count; i++)
    {
        if( m_objects[i].do_something() )
        {
            m_allocated_count -= 1;
            if (m_allocated_count != 0)
            {
                // Not good if order of processing the objects is important.
                Object tmp = m_objects[i];
                m_objects[i] = m_objects[m_allocated_count];
                m_objects[m_allocated_count] = tmp;
                // Potential underflow but controlled.
                i -= 1;
            }
        }
    }
}

} // namespace ObjectPoolNS
