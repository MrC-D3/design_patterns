#ifndef RECEIVER_HPP
#define RECEIVER_HPP


namespace Command
{

class Receiver
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void operation1();

    // Potentially operation2() and so on.
    // In game context, they can be something like jump(), shoot(), etc.
};

} // namespace Command


#endif // RECEIVER_HPP