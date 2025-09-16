#include "09_interpreter/context.hpp"


namespace Interpreter
{

Context::Context()
: m_values()
{}
    
void Context::assign(
  const std::shared_ptr<AbstractExpression>& key, 
  const bool value)
{
    // The pointer is still unique even if smart thanks to comparison operators.
    m_values[key] = value;
}

bool Context::lookup(const std::shared_ptr<const AbstractExpression>& key) const
{
    return m_values.at(key);
}

} // namespace Interpreter
