#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>


class Singleton
{
  public:
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;

    static Singleton* get_instance(int counter);

    void print_counter();

  protected:
    Singleton(int counter = 0);

    static Singleton* unique_instance;
    static std::mutex mutex;
    int m_counter;
};

#endif