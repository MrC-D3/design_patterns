#include "22_interpreter/nonterminal_expression.hpp"
#include "22_interpreter/context.hpp"


namespace Interpreter
{

NonterminalExpression0::NonterminalExpression0(
  const std::shared_ptr<AbstractExpression>& operand1, 
  const std::shared_ptr<AbstractExpression>& operand2)
  : m_operand1(operand1), m_operand2(operand2)
{}

bool NonterminalExpression0::interpret(const Context& context) const
{
    return ( m_operand1->interpret(context) && m_operand2->interpret(context) );
}

} // namespace Interpreter
