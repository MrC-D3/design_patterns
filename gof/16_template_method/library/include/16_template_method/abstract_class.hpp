#ifndef ABSTRACT_CLASS_HPP
#define ABSTRACT_CLASS_HPP


namespace TemplateMethod
{

class AbstractClass
{
  public:
    virtual ~AbstractClass() = default;
    // Default c'tors and operator= overloads, both copy and move.

    void template_method();

  protected:
    virtual void primitive_operation1() = 0;
    virtual void hook();
    virtual void primitive_operation2() = 0;
};

} // namespace TemplateMethod


#endif // ABSTRACT_CLASS_HPP