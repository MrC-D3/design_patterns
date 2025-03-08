#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>
#include <mutex>


namespace SingletonNS
{
  
class Singleton
{
  public:
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;

    static Singleton& get_instance(const std::int64_t& counter);

    void print_counter() const;

  // Singleton is not meant to be subclassed, so private not protected.
  private:
    explicit Singleton(const std::int64_t counter = 0);

    std::int64_t m_counter;
};

} // namespace SingletonNS


#endif // SINGLETON_HPP