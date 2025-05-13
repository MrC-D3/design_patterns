#include "22_interpreter/terminal_expression.hpp"


namespace Interpreter
{

TerminalExpression::TerminalExpression(bool value)
  : m_value(value)
{}

bool TerminalExpression::interpret()
{
    return m_value;
}

} // namespace Interpreter