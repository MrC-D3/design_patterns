#ifndef DATA_LOCALITY_HPP
#define DATA_LOCALITY_HPP

#include <cstdint>


namespace DataLocalityNS
{

// Invece che avere un array di oggetti della class A che contiene un oggetto B
//  di cui chiamo il metodo B::m(), gli oggetti di A diventano indici di un
//  array di B?
// Come esempio, faccio un refactor dell'esempio del Component.
// Hot/Cold splitting: tecnica per separare i dati che verranno processati (hot)
//  da quelli che non lo verranno (cold); gli hot finiscono in una classe le cui
//  istanze verranno salvate in memoria contigua (i.d. array) per ottimizzare il
//  caching.

using Container = uint8_t;

class Component1
{
  public:
    // Default d'tor, c'tor and operator= overloads, both copy and move.
    explicit Component1(const Container& container);

    void do_something();

  private:
    Container m_container;
};


} // DataLocalityNS


#endif // DATA_LOCALITY_HPP