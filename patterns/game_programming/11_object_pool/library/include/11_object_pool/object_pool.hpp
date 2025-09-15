// Allocating objects at runtime is slow and may lead to memory fragmentation in
//  the heap. Here comes the Object Pool Pattern.

#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include <array>
#include <cstdint>


namespace ObjectPoolNS
{

class Object
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Init method to emulate a fresh new allocation.
    //  It can be called by ObjectPool before returning an object.
    //  Or by the new owner of the object.
    void init(const int data);

    // Do some object-related method, like update() or render().
    // Return if work's done and so the object can be destroyed.
    bool do_something();

    // Some data and methods.
    int m_data{0};
};

class ObjectPool
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Active the object at m_objects[m_allocated_count] and init its state.
    // Deallocation is usually implicit when the object finishes its work.
    // Otherwise, you can define an ObjectProxy and its c'tor/d'tor are
    //  responsible to allocate/deallocate using the pool.
    void allocate(const int data);

    void all_do_something();

  private:
    // The pool can potentially contain heterogeneous objects too.
    //  When homogeneous objects, they usually know they are part of a pool.
    std::array<Object, 100> m_objects;
    uint8_t m_allocated_count{0};
};

} // namespace ObjectPoolNS

#endif // OBJECT_POOL_HPP