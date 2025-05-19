#ifndef TERMINAL_EXPRESSION_HPP
#define TERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"
#include <string>


namespace Interpreter
{

class TerminalExpression final : public AbstractExpression
{
  public:
    ~TerminalExpression() = default;
    TerminalExpression(const std::string& name);

    bool interpret(Context& context) override;

  private:
    std::string m_name;
};

} // namespace Interpreter

#endif // TERMINAL_EXPRESSION_HPP
