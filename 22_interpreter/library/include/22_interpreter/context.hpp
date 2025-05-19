#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <map>
#include "22_interpreter/abstract_expression.hpp"


namespace Interpreter
{

class Context
{
  public:
    Context();
    
    void assign(AbstractExpression* key, bool value);
    bool lookup(const AbstractExpression* key);
    
  private:
    std::map<const AbstractExpression*, bool> m_values;
};

} // namespace Interpreter


#endif // CONTEXT_HPP
