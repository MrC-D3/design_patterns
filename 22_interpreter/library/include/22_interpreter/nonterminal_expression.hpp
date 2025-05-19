#ifndef NONTERMINAL_EXPRESSION_HPP
#define NONTERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"


namespace Interpreter
{

class NonterminalExpression0 final : public AbstractExpression
{
  public:
    ~NonterminalExpression0() = default;
    NonterminalExpression0(AbstractExpression* operand1, AbstractExpression* operand2);

    bool interpret(Context& context) override;

  private:
    AbstractExpression* m_operand1;
    AbstractExpression* m_operand2;
};

// NonterminalExpression1, ..., NonterminalExpressionN.

} // namespace Interpreter

#endif // NONTERMINAL_EXPRESSION_HPP
