#include "07_event_queue/event_queue.hpp"
#include <iostream>


namespace EventQueueNS
{

/*
** Implementation of EventQueue.
*/
void EventQueue::safe_push(const int event)
{
    std::unique_lock lock(m_mutex);

    m_events.push(event);

    m_cv.notify_all();
}

const int EventQueue::safe_pop()
{
    std::unique_lock lock(m_mutex);

    if( m_events.empty() )
    {
        m_cv.wait(lock, [&](){
          return !m_events.empty();
        });
    }

    // The event should be consumed by only one entity, so it can be removed.
    auto to_return = m_events.back();
    m_events.pop();
    return to_return;
}

/*
** Implementation of Pusher.
*/
void Pusher::add_event(EventQueue& queue)
{
    queue.safe_push(5);
}

/*
** Implementation of Popper.
*/
void Popper::consume_event(EventQueue& queue)
{
    auto result = queue.safe_pop();
    std::cout << "I'm the Popper. Consuming: " << result << ".\n";
}

} // namespace EventQueueNS
