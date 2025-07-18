// The Singleton design pattern is considered an anti-pattern and one of the
//  reasons is the difficulty to test it: a function under test that depends on 
//  a Singleton may get that instance by itself (hidden hard-code dependency) 
//  instead of receive it by parameter, so - if the case - refactor the code:
//  - create a base class you can inherit from to make the Singleton class and
//   the mock class used for testing;
//  - make the function under test receives this base class as parameter, but
//   this parameter is the Singleton instance by default.

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>


namespace SingletonNS
{

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

} // namespace SingletonNS


#endif // SINGLETON_HPP