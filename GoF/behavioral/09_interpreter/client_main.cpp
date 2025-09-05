// An Interpreter has typically 2 phases:
// 1. Lexing/Tokenization, where you go from a sequence of characters to a 
//  sequence of Expressions;
// 2. Parsing, where you go from the sequence of Expressions to a single 
//  composite Expression.
// In this example the Tokenization (i.e. processing X, Y and the AND operator)
//  is skipped, while the Parsing (i.e. creating the sub-expressions and the 
//  single composite expression sentence) is done manually.

#include "09_interpreter/abstract_expression.hpp"
#include "09_interpreter/nonterminal_expression.hpp"
#include "09_interpreter/terminal_expression.hpp"
#include "09_interpreter/context.hpp"

#include <iostream>


using namespace Interpreter;

int main()
{
    /*
    **  Case 1: "true && true".
    */
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

    /*
    **  Case 2: "false && true".
    */
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
