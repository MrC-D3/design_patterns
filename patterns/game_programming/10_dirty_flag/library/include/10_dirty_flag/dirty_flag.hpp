#ifndef DIRTY_FLAG_HPP
#define DIRTY_FLAG_HPP


namespace DirtyFlagNS
{

class ParentClass;

class ChildClass
{
  public:
    // Default d'tor, c'tors and operator= overlaods, both copy and move.
    explicit ChildClass(const ParentClass& parent);

    void set_data(const int new_data);
    int get_data();
    void set_flag(const bool dirty);

  private:
    const ParentClass& m_parent;

    // It can also be moved in the parent, especially if many childre.
    bool m_dirty_flag{true};

    // Some data A related to somee data B, so if B changes also A must change.
    // E.g.: A = 2*B, but usually more complex to justify lazy update.
    int m_data{0};
};

class ParentClass
{
  public:
    explicit ParentClass(const int data);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void set_data(const int data);
    int get_data() const;

    // Public for shortiness.
    ChildClass m_child;
    // The data B.
    int m_data;
};

} // namespace DirtyFlagNS


#endif // DIRTY_FLAG_HPP