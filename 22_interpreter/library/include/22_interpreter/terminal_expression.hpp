#ifndef TERMINAL_EXPRESSION_HPP
#define TERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"

#include <string>
#include <memory>


namespace Interpreter
{

class TerminalExpression final : 
  // All the Base classes must have their access specifier.
  public AbstractExpression, 
  public std::enable_shared_from_this<TerminalExpression>
{
  public:
    ~TerminalExpression() = default;
    TerminalExpression(const std::string& name);

    TerminalExpression(const TerminalExpression& origin) = default;
    TerminalExpression& operator=(const TerminalExpression& origin) = default;

    TerminalExpression(TerminalExpression&& origin) = default;
    TerminalExpression& operator=(TerminalExpression&& origin) = default;

    bool interpret(const Context& context) const override;

  private:
    std::string m_name;
};

} // namespace Interpreter

#endif // TERMINAL_EXPRESSION_HPP
