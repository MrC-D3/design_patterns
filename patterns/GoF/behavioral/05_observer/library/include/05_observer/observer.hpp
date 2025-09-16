#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "05_observer/observer_interface.hpp"
#include "05_observer/subject.hpp"

#include <memory>
#include <string>
#include <mutex>
#include <condition_variable>
#include <atomic>


namespace ObserverNS
{

/*
** Solution 01: Classic.
*/
class Observer final : public ObserverInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    
    void update() override;
};

// Potentially other concrete Observer: one interested in physics events, one in
//  sound events, etc.

/*
** Solution 02: Thread Safe.
** From "Tony Van Eerd: Thread-safe Observer Pattern - You're doing it wrong".
*/
class Listener
{
  public:
    virtual ~Listener() = default;
    Listener();

    virtual void fooChanged(std::string s) = 0;

    void stop();
    void for_every_change();
    void check_for_change();
    void inform_fooChanged(std::string s);

  private:
    std::mutex m_mutex;
    std::condition_variable m_condvar;
    bool m_newData;
    std::atomic<bool> m_keepGoing;
    std::string m_info;
};

} // namespace ObserverNS

#endif