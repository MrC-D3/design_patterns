#include "09_interpreter/terminal_expression.hpp"
#include "09_interpreter/context.hpp"


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
