#include "07_event_queue/event_queue.hpp"

#include <gtest/gtest.h>
#include <thread>


using namespace EventQueueNS;

class EventQueueFixture : public ::testing::Test
{
  protected:
    ~EventQueueFixture()
    {}

    EventQueueFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(EventQueueFixture, test_name)
{
    EventQueue eventQueue;
    Pusher pusher;
    Popper popper;

    std::thread t_popper(&Popper::consume_event, &popper, std::ref(eventQueue));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    pusher.add_event(eventQueue);

    t_popper.join();
}