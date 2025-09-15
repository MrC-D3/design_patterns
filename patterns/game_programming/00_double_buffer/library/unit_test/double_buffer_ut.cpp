#include "00_double_buffer/double_buffer.hpp"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace DoubleBufferNS;

class DoubleBufferSuite : public ::testing::Test
{
  protected:
    ~DoubleBufferSuite()
    {}

    DoubleBufferSuite()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};


TEST_F(DoubleBufferSuite, init)
{
    DoubleBuffer dBuffer(320, 200); // Risoluzione CGA.

    for(const auto& pixel : dBuffer.get_buffer())
    {
        ASSERT_EQ(pixel, 0);
    }
}

TEST_F(DoubleBufferSuite, draw_on_next)
{
    DoubleBuffer dBuffer(320, 200);

    dBuffer.draw(160, 100);

    for(const auto& pixel : dBuffer.get_buffer())
    {
        ASSERT_EQ(pixel, 0);
    }
}

TEST_F(DoubleBufferSuite, swap)
{
    DoubleBuffer dBuffer(320, 200);

    dBuffer.draw(160, 100);
    dBuffer.swap();

    auto buffer = dBuffer.get_buffer();
    for(auto j = 0; j < 200; j++)
    {
        for(auto i = 0; i < 320; i++)
        {
            if( (i==160) && (j==100) )
            {
                ASSERT_EQ(buffer[j*320+i], 0xFFFFFFFF);
            }
            else
            {
                ASSERT_EQ(buffer[j*320+i], 0);
            }
        }
    }
}

TEST_F(DoubleBufferSuite, clear)
{
    DoubleBuffer dBuffer(320, 200);

    dBuffer.draw(160, 100);
    dBuffer.clear();
    dBuffer.swap();

    for(const auto& pixel : dBuffer.get_buffer())
    {
        ASSERT_EQ(pixel, 0);
    }
}

TEST_F(DoubleBufferSuite, sync)
{
    DoubleBuffer dBuffer(320, 200);

    std::mutex mutex_buffer;
    std::condition_variable cv_buffer;
    bool showable{false};

    std::thread show(
      [&](){
        for(auto offset = 0; offset < 10; offset++)
        {
            std::unique_lock lock_buffer(mutex_buffer);
            cv_buffer.wait(lock_buffer,
              [&](){
                return showable;
            });

            auto buffer = dBuffer.get_buffer();

            showable = false;
            lock_buffer.unlock();
            cv_buffer.notify_all();

            for(auto j = 0; j < 200; j++)
            {
                for(auto i = 0; i < 320; i++)
                {
                    if( (i==offset) && (j==0) )
                    {
                        ASSERT_EQ(buffer[j*320+i], 0xFFFFFFFF);
                    }
                    else
                    {
                        ASSERT_EQ(buffer[j*320+i], 0);
                    }
                }
            }            
            // 24 FPS: 1 frame ogni 41ms.
            std::this_thread::sleep_for( std::chrono::milliseconds(41) );
        }
    });

    for(auto i = 0; i < 10; i++)
    {
        dBuffer.draw(i,0);

        std::unique_lock lock_buffer(mutex_buffer);
        cv_buffer.wait(lock_buffer,
          [&](){
            return !showable;
        });
        dBuffer.swap();
        showable = true;
        lock_buffer.unlock();
        cv_buffer.notify_all();

        dBuffer.clear();
    }

    show.join();
}