#ifndef RECEIVER_HPP
#define RECEIVER_HPP


namespace Command
{

class Receiver
{
  public:
    ~Receiver() = default;
    Receiver() = default;

    Receiver(const Receiver& origin) = default;
    Receiver& operator=(const Receiver& origin) = default;

    Receiver(Receiver&& origin) = default;
    Receiver& operator=(Receiver&& origin) = default;

    void operation();
};

} // namespace Command

#endif // RECEIVER_HPP