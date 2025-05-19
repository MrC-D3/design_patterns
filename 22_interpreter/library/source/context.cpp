#include "22_interpreter/context.hpp"


namespace Interpreter
{

Context::Context()
  : m_values()
{}
    
void Context::assign(AbstractExpression* key, bool value)
{
    // Using the pointer as key, because it's unique.
    m_values[key] = value;
}

bool Context::lookup(const AbstractExpression* key)
{
    return m_values.at(key);
}

} // namespace Interpreter
