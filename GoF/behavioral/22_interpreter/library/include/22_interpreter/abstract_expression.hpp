#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP


namespace Interpreter
{

class Context;

class AbstractExpression
{
  public:
    virtual ~AbstractExpression() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual bool interpret(const Context& context) const = 0;
};

} // namespace Interpreter


#endif // ABSTRACT_EXPRESSION_HPP
