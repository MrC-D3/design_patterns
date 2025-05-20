#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <map>
#include <memory>

#include "22_interpreter/abstract_expression.hpp"


namespace Interpreter
{

class Context
{
  public:
    ~Context() = default;
    Context();

    Context(const Context& origin) = default;
    Context& operator=(const Context& origin) = default;

    Context(Context&& origin) = default;
    Context& operator=(Context&& origin) = default;
    
    // Using std::shared_ptr<Base>& doesn't work.
    // Becauae a "non-const lvalue reference" requires an exact type match. 
    void assign(const std::shared_ptr<AbstractExpression>& key, bool value);
    bool lookup(const std::shared_ptr<const AbstractExpression>& key) const;
    
  private:
    std::map<std::shared_ptr<const AbstractExpression>, bool> m_values;
};

} // namespace Interpreter


#endif // CONTEXT_HPP
