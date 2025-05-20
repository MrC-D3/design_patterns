#ifndef NONTERMINAL_EXPRESSION_HPP
#define NONTERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"

#include <memory>


namespace Interpreter
{

class NonterminalExpression0 final : public AbstractExpression
{
  public:
    ~NonterminalExpression0() = default;
    NonterminalExpression0(
      const std::shared_ptr<AbstractExpression>& operand1, 
      const std::shared_ptr<AbstractExpression>& operand2);

    NonterminalExpression0(const NonterminalExpression0& origin) = delete;
    NonterminalExpression0& operator=(
      const NonterminalExpression0& origin) = delete;

    NonterminalExpression0(NonterminalExpression0&& origin) = default;
    NonterminalExpression0& operator=(NonterminalExpression0&& origin) = default;

    bool interpret(const Context& context) const override;

  private:
    std::shared_ptr<const AbstractExpression> m_operand1;
    std::shared_ptr<const AbstractExpression> m_operand2;
};

// NonterminalExpression1, ..., NonterminalExpressionN.

} // namespace Interpreter

#endif // NONTERMINAL_EXPRESSION_HPP
