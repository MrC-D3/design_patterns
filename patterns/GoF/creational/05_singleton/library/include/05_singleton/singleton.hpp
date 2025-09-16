#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>
#include <iostream>


namespace SingletonNS
{

/*
** Classic solution.
*/
class Singleton 
{
  public:
    // Equivalent to "Singleton const&".
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;
    // Default d'tor, c'tors and operator= overload, for move.

    // Static method to make it a class-method, not an instance-method.
    static Singleton& get_instance(const std::int64_t counter);

    void print_counter() const;

  // You can potentially subclass: imagine a filesystem class implemented
  //  differently for each platform.
  protected:
    explicit Singleton(const std::int64_t counter = 0);

    std::int64_t m_counter;
};

/*
** Modern solution.
*/
// The Singleton design pattern is considered an anti-pattern and one of the
//  reasons is the difficulty to test it: a function under test that depends on 
//  a Singleton may get that instance by itself (hidden hard-code dependency) 
//  instead of receive it by parameter, so - if the case - refactor the code:
//  - create a class C with all the Singleton's methods as virtual, but without
//   the single static instance;
//  - create a struct S that just wraps a single instance I of the class C.
//  Now you can:
//  - mock class C for testing purpose;
//  - pass S::I as default parameter to all the functions that was depending on
//   the Singleton.
class ClassC
{
  public:
    // Virtual so it can be used as base class for mocking.
    virtual ~ClassC() = default;
    explicit ClassC(const std::int64_t counter = 0)
    : m_counter{counter}
    {}
    // Default c'tors and operator= overloads, both copy and move.

    virtual void print_counter() const
    {
        std::cout << m_counter << std::endl;
    };

  protected:
    std::int64_t m_counter;
};

struct SingletonWrapper
{
    ClassC instance;
};

// Functions defined in the header must be inlined or the user will include them
//  twice: from the library .a and from the header.
// Class methods defined in the header are inlined by default.
inline ClassC& getDefaultClassC()
{
    // Lazy initialization.
    static SingletonWrapper wrapper;
    return wrapper.instance;
}

// Usually Singletons run in groups, so the implementation change a little.
class Service1
{};
class Service2
{};

struct Services
{
    Services(Service1& instanceS1_, Service2& instanceS2_)
    : instanceS1{instanceS1_}, instanceS2{instanceS2_}
    {}
    
    // By references, so they must be stored somewhere else.
    Service1& instanceS1;
    Service2& instanceS2;
};

inline Services& getDefaultServices()
{
    static Service1 serviceS1;
    static Service2 serviceS2;
    static Services services(serviceS1, serviceS2);

    return services;
}

} // namespace SingletonNS


#endif // SINGLETON_HPP