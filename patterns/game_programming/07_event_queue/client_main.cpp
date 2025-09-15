#include "07_event_queue/event_queue.hpp"

#include <thread>


int main()
{
    using namespace EventQueueNS;
    EventQueue events;
    Pusher creator;
    Popper consumer;

    std::thread thread_events(&Popper::consume_event, &consumer, 
      std::ref(events));

    creator.add_event(events);

    thread_events.join();

    return 0;
}
