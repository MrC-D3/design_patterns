#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP


namespace Interpreter
{

class Context;

class AbstractExpression
{
  public:
    virtual ~AbstractExpression() = default;

    virtual bool interpret(Context& context) = 0;
};

} // namespace Interpreter

#endif // ABSTRACT_EXPRESSION_HPP
