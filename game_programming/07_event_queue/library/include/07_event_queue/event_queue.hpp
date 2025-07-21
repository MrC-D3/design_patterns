// Event Queue, Command and Observer are very similar; the Event Queue can be 
//  seen as a buffer async version of the other two, so time decoupling.
// Async means that the Event must store any states that can be different when
//  the Event is dispatched.

#ifndef EVENT_QUEUE_HPP
#define EVENT_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>


namespace EventQueueNS
{

/*
** The EventQueue class, but maybe it should be part of the class that consumes
**  the events. 
*/
class EventQueue
{
  public:
    // Default d'tor, c'tor and operator= overloads; just move because of mutex.

    // For memory optimization, the event can be created by the Queue and then
    //  given to the client to be filled in (for complex event objects).
    void safe_push(const int event);
    const int safe_pop();

  private:
    std::queue<int> m_events;
    std::mutex m_mutex;
    std::condition_variable m_cv;
};

class Pusher
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void add_event(EventQueue& queue);
};

/*
** Poppor class, the one that consumes events.
*/
class Popper
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void consume_event(EventQueue& queue);
};

} // namespace EventQueueNS

#endif // EVENT_QUEUE_HPP