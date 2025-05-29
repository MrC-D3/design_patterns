#ifndef NONTERMINAL_EXPRESSION_HPP
#define NONTERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"

#include <memory>


namespace Interpreter
{

class NonterminalExpression0 final : public AbstractExpression
{
  public:
    NonterminalExpression0(
      const std::shared_ptr<AbstractExpression>& operand1, 
      const std::shared_ptr<AbstractExpression>& operand2);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    bool interpret(const Context& context) const override;

  private:
    std::shared_ptr<const AbstractExpression> m_operand1;
    std::shared_ptr<const AbstractExpression> m_operand2;
};

// NonterminalExpression1, ..., NonterminalExpressionN.

} // namespace Interpreter


#endif // NONTERMINAL_EXPRESSION_HPP
