#include "22_interpreter/nonterminal_expression.hpp"


namespace Interpreter
{

NonterminalExpression0::NonterminalExpression0(
  AbstractExpression* operand1, AbstractExpression* operand2)
  : m_operand1(operand1), m_operand2(operand2)
{}

bool NonterminalExpression0::interpret()
{
    return ( m_operand1->interpret() && m_operand2->interpret() );
}

} // namespace Interpreter