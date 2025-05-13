#ifndef TERMINAL_EXPRESSION_HPP
#define TERMINAL_EXPRESSION_HPP

#include "22_interpreter/abstract_expression.hpp"


namespace Interpreter
{

class TerminalExpression final : public AbstractExpression
{
  public:
    ~TerminalExpression() = default;
    TerminalExpression(bool value);

    bool interpret() override;

  private:
    bool m_value;
};

} // namespace Interpreter

#endif // TERMINAL_EXPRESSION_HPP