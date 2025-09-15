#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP


namespace UpdateMethodNS
{

/*
** Example 01: classic solution with a single class hierarchy. 
*/
class UpdatableInterface
{
  public:
    ~UpdatableInterface() = default;

    UpdatableInterface(double start_position);
    // Default c'tors and operator= overloads, both copy and move.

    virtual void update(double MS_PER_UPDATE) = 0;

    double getPosition();

  protected:
    double m_position;
};

/*
** Example 02: delegate the update to member data class (e.g. State pattern).
**  You can share the State hierarchy among indipendent class hierarchies.
**  You can limit subclassing but still re-using common code.
*/

} // namespace UpdateMethodNS


#endif // UPDATABLE_HPP