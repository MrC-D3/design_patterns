#ifndef DOUBLE_BUFFER_HPP
#define DOUBLE_BUFFER_HPP

#include <vector>
#include <cstdint>


namespace DoubleBufferNS
{

class DoubleBuffer
{
  public:
    DoubleBuffer(std::uint32_t width, std::uint32_t height);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void draw(std::uint16_t x, std::uint16_t y);
    
    void swap();

    void clear();

    const std::vector<std::uint32_t>& get_buffer();

  private:
    std::vector<std::uint32_t> m_current_buffer;
    std::vector<std::uint32_t> m_next_buffer;
    std::uint32_t m_height;
    std::uint32_t m_width;
};

}

#endif // DOUBLE_BUFFER_HPP
