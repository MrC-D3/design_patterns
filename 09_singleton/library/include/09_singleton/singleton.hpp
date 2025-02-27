#ifndef SINGLETON_HPP
#define SINGLETON_HPP

class Singleton
{
  public:
    static Singleton* get_instance();

    void print_counter();

  protected:
    Singleton(int counter = 0);
    static Singleton* unique_instance;
    int m_counter;
};

#endif