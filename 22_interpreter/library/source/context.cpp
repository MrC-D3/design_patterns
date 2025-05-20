#include "22_interpreter/context.hpp"


namespace Interpreter
{

Context::Context()
  : m_values()
{}
    
void Context::assign(const std::shared_ptr<AbstractExpression>& key, 
  const bool value)
{
    // Using the pointer as key, because it's unique.
    // What to in case of smart pointers?
    // Keeping the raw pointer will expose it and be dangerous.
    m_values[key] = value;
}

bool Context::lookup(const std::shared_ptr<const AbstractExpression>& key) const
{
    return m_values.at(key);
}

} // namespace Interpreter
