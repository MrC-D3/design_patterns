/ 5 3 +
int postfix_notation(std::vector<std::string> expression)
{
    std::stack<std::string> myStack;
    int result = 0;

    for(auto it = expression.begin(); it != expression.end(); it++)
    {
        if(*it == "+")
        {
            auto operand1 = myStack.top();
            auto operand2 = myStack.top();
            result = std::stoi(operand1) + std::stoi(operand2);

            myStack.push(std::to_string(result));
        }
        else if(*it == "-")
        {
            auto operand2 = myStack.top();
            auto operand1 = myStack.top();
            result = std::stoi(operand1) - std::stoi(operand2);

            myStack.push(std::to_string(result));
        }
        else if(*it == "*")
        {
            auto operand2 = myStack.top();
            auto operand1 = myStack.top();
            result = std::stoi(operand1) * std::stoi(operand2);

            myStack.push(std::to_string(result));
        }
        else if(*it == "/")
        {
            auto operand2 = myStack.top();
            auto operand1 = myStack.top();
            result = std::stoi(operand1) / std::stoi(operand2);

            myStack.push(std::to_string(result));
        }
        else
        {
            myStack.push(*it);
        }
    }

    return result;
}

// Or Polish notation: + 5 - 3 2.
int prefix_notation(std::vector<std::string> expression)
{
    std::stack<std::string> myStack;
    int result = 0;

    int count = 0;
    for(auto it = expression.begin(); it != expression.end(); it++)
    {
        if(*it == "+" || *it == "-")
        {
            count = 0;
        }
        else
        {
            count += 1;
            if(count == 2)
            {
                auto operand2 = std::stoi(*it);
                auto operand1 = std::stoi(myStack.top());
                auto toDo = myStack.top();

                if(toDo == "+")
                {
                    result = operand1 + operand2;
                }
                else
                {
                    result = operand1 - operand2;
                }

                myStack.push(std::to_string(result));
                count = 1;
            }
        }
    }

    return result;
}