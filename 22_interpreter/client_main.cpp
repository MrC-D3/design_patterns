#include "22_interpreter/abstract_expression.hpp"
#include "22_interpreter/nonterminal_expression.hpp"
#include "22_interpreter/terminal_expression.hpp"
#include "22_interpreter/context.hpp"

#include <iostream>


using namespace Interpreter;

int main()
{
    auto expression1 = std::make_shared<TerminalExpression>("X");
    auto expression2 = std::make_shared<TerminalExpression>("Y");
    NonterminalExpression0 sentence(expression1, expression2);
    Context context;
    
    context.assign(expression1, true);
    context.assign(expression2, true);
    auto result = sentence.interpret(context);
    if(result)
    {
        std::cout << "Result is true, correct!\n";
    }
    else
    {
        std::cout << "Result is false, wrong!\n";
    }

    context.assign(expression1, false);
    result = sentence.interpret(context);
    if(result)
    {
        std::cout << "Result is true, wrong!\n";
    }
    else
    {
        std::cout << "Result is false, correct!\n";
    }

    return 0;
}
