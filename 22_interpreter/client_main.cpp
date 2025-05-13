#include "22_interpreter/abstract_expression.hpp"
#include "22_interpreter/nonterminal_expression.hpp"
#include "22_interpreter/terminal_expression.hpp"

#include <iostream>


using namespace Interpreter;

int main()
{
    TerminalExpression expression1(true);
    TerminalExpression expression2(true);
    NonterminalExpression0 sentence(&expression1, &expression2);

    auto result = sentence.interpret();
    if(result)
    {
        std::cout << "Result is true.\n";
    }
    else
    {
        std::cout << "Result is false.\n";
    }

    return 0;
}