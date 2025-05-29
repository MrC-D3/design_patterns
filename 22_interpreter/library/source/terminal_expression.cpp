#include "22_interpreter/terminal_expression.hpp"
#include "22_interpreter/context.hpp"


namespace Interpreter
{

TerminalExpression::TerminalExpression(const std::string& name)
: m_name(name)
{}

bool TerminalExpression::interpret(const Context& context) const
{
    return context.lookup(shared_from_this());
}

} // namespace Interpreter
