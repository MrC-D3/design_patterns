#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>


class Singleton
{
  public:
    Singleton(Singleton& s) = delete;
    Singleton& operator=(Singleton& s) = delete;

    static Singleton* get_instance();

    void print_counter();

  protected:
    Singleton(int counter = 0);

    static Singleton* unique_instance;
    static std::lock_guard mutex;
    int m_counter;
};

#endif