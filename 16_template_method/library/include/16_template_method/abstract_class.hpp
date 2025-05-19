#ifndef ABSTRACT_CLASS_HPP
#define ABSTRACT_CLASS_HPP


namespace TemplateMethod
{

class AbstractClass
{
  public:
    virtual ~AbstractClass() = default;
    AbstractClass() = default;

    AbstractClass(const AbstractClass& origin) = default;
    AbstractClass& operator=(const AbstractClass& origin) = default;

    AbstractClass(AbstractClass&& origin) = default;
    AbstractClass& operator=(AbstractClass&& origin) = default;

    void template_method();

  protected:
    virtual void primitive_operation1() = 0;
    virtual void hook();
    virtual void primitive_operation2() = 0;
};

} // namespace TemplateMethod


#endif // ABSTRACT_CLASS_HPP