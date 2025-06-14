#include "00_double_buffer/double_buffer.hpp"


namespace DoubleBufferNS
{

// In the initializer list, you're calling the c'tor of the members.
DoubleBuffer::DoubleBuffer(std::uint32_t width, std::uint32_t height)
: m_width(width), m_height(height), m_current_buffer(width*height, 0), 
  m_next_buffer(width*height, 0)
{}

void DoubleBuffer::draw(std::uint16_t x, std::uint16_t y)
{
    // TODO: bound checking.

    m_next_buffer[y*m_width + x] = 0xFFFFFFFF; // RGBA.
}

void DoubleBuffer::swap()
{
    // Zero-copy swap. Even faster if std::vector<T>*.
    std::swap(m_current_buffer, m_next_buffer);
}

void DoubleBuffer::clear()
{
    std::fill(m_next_buffer.begin(), m_next_buffer.end(), 0x00000000);
}

const std::vector<std::uint32_t>& DoubleBuffer::get_buffer()
{
    return m_current_buffer;
}

} // namespace DoubleBufferNS
