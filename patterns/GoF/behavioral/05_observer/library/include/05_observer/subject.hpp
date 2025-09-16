#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "05_observer/subject_interface.hpp"

#include <cstdint>
#include <mutex>
#include <string>
#include <vector>


namespace ObserverNS
{

/*
** Solution 01: Classic.
*/
class Subject final : public SubjectInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void setState(const std::int64_t state);
    const std::int64_t& getState() const;

  private:
    std::int64_t m_state;
};

/*
** Solution 02: Thread Safe.
** From "Tony Van Eerd: Thread-safe Observer Pattern - You're doing it wrong".
*/
class Listener;
class SubjectSafe
{
  public:
    void set_state(std::string str);
    std::string get_state();
    void addListener(Listener * listener);
    bool removeListener(Listener * listener);

  private:
    void notifyListeners();

    std::string m_state;
    std::recursive_mutex m_mutex;
    std::vector<Listener*> m_listeners;
};

} // namesapce ObserverNS


#endif // SUBJECT_HPP