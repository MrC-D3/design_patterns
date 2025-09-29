#include <vector>
#include <list>
#include <string>
#include <stack>
#include <array>

/*
** Log2 (or how many bits to represent N).
*/
// Forward (or multiplication) technique.
int log2_forward(int N)
{
    int result, i;

    for(result = 0, i = 1; i <= N; result += 1, i += i); // Better than i*=2.

    return result; 
}
// Shift (division) technique.
int log2_shift(int N)
{
    int result;

    for(result = 0; N > 0; N >>= 1, result += 1); // Better than i/=2.

    return result; 
}

/*
** Sieve of Eratosthenes (or how to find the prime numbers till N).
** Cost N*H_N, where H_N is the Harmonic Serie till 1/N: (1 + ½ + … + 1/N).
**  Cost can be approximated to ln(N)+gamma, where gamma is the Eulero constant
**  equivalent to 0,577.
*/
void sieve_of_eratosthenes(std::vector<bool>& is_prime) // is_prime(N, true).
{
    // Why stop at i*i<is_prime.size()?
    // Number A=x*x; if x is an int A is a perfect root, otherwise A=b*c with b
    //  or c <=x. So, if A is the greatest value in is_prime[], every value <=A
    //  is already marked by min(b, c).
    for (auto i = 2; i*i < is_prime.size(); i++)
    {
        if (is_prime[i])
        {
            // Start at i*i e not at i+i because every i*(i-1), ..., i*(2) was
            //  already marked by previous iterations.
            for (auto j = i*i; j < is_prime.size(); j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

/*
** Josephus problem (OR how to delete the M-th element among N elements and
**  repeat it until only one element is left OR how to find the survivor among a
**  group of N elements and step M).
*/
int josephus_problem(std::list<int> elements, int M)
{
    auto it = elements.begin();

    while (elements.size() > 1)
    {
        // Reach the M-th element (you're already on element 0, so M-1 steps).
        for (auto i = 1; i < M; i++)
        {
            ++it;
            if (it == elements.end())
            {
                it = elements.begin();
            }
        }

        // erase() returns the iterator to the element after the one erased.
        it = elements.erase(it);
        if (it == elements.end())
        {
            it = elements.begin();
        }
    }

    // or front(), it's the same.
    return elements.back();
}
// Init: elements[i] = (i+1) % elements.size().
int josephus_problem(std::vector<int> elements, int M) 
{
    auto size = elements.size();
    auto i = 0;
    while (size > 1)
    {
        // Reach the (M-1)-th element (already on element 0, so M-1 steps).
        for (auto j = 1; j < M-1; j++)
        {
            i = elements[i];
        }
        // Connect (M-1) to (M+1).
        auto next = elements[elements[i]];
        elements[i] = next;
        i = next;
        size -= 1;
    }

    return i;
}
// Math formula: from O(N*M) to O(N).
int josephus_problem(int N, int M)
{
    // Looking for the survivor, so if 1 element, you already got it.
    if (N == 1)
    {
        return 0;
    }

    // The erased one is at [M-1], so the survivor will always be at [M] (%N).
    //  In fact, if N==2, the recursion returns 0 and the local solution is M%N.
    return (josephus_problem(N-1, M) + M) % N;
}

/*
** Math expression can be written with infix, prefix or postfix notation.
**  Here an example of prefix (or Polish) notation , but reading the expression
**   from left to right gives the postfix notation (or reverse Polish).
*/
int prefix_math(const std::vector<std::string> expression)
{
    std::stack<int> operands;
    // Checking it<expression.rend() has no real sense.
    for(auto it = expression.rbegin(); it != expression.rend(); it++)
    {
        try
        {
            auto operand = std::stoi(*it);
            operands.push(operand);
        }
        catch(...)
        {
            auto operand1 = operands.top();
            operands.pop();
            auto operand2 = operands.top();
            operands.pop();

            auto result = 0;
            if (*it == "+")
            {
                result = operand1 + operand2;
            }
            else if (*it == "-")
            {
                result = operand1 - operand2;
            }
            else if (*it == "*")
            {
                result = operand1 * operand2;
            }
            else if (*it == "/")
            {
                result = operand1 / operand2;
            }

            operands.push(result);
        }
    }

    return operands.top();
}

/*
** Horner’s method (or how to evaluate a polynomial with in the lowest number of
**  moltiplication and addition): sees the polynomial as: a0 + x(a1 + x(a2). 
*/
int horner_method(std::vector<int>& coefficients, int x)
{
    // Maybe indexes are more efficient, but iterators are more C++ idiomatic.
    int result{coefficients.back()};
    for (auto it = coefficients.rbegin()+1; it != coefficients.rend(); it++)
    {
        result = result*x + *it;
    }

    return result;
}

/*
** Euclidean Algorithm (or how to find the GCD between m and n where m > n).
** Cost is O(log(n)).
*/
unsigned euclidean_algorithm(unsigned m, unsigned n)
{
    if (n == 0)
    {
        return m;
    }

    // As always, the recursive solution can cause stack overflow.
    return euclidean_algorithm(n, m%n);
}

/*
** Hanoi Towers problem (or how to move N discs from tower 1 to tower 3, where 
**  each disc can only be over bigger discs).
** Note how the smallest disc (i.e. #1) is moved every 2 moves, like when you 
**  mark vertical lines on a rule and the smallest one is every 2 marks. Analogy
**  also with the number of LSB at 0 in binary even numbers: 1 (10, 110, ...).
*/
void hanoi_towers(std::array<std::stack<int>, 3>& towers, int N, int source, 
  int destination)
{
    // Ending case.
    if (N == 0)
    {
        return;
    }

    auto support = 3 - source - destination;

    // Move above discs.
    hanoi_towers(towers, N-1, source, support);

    // Move discs.
    auto disc = towers[source].top();
    towers[source].pop();
    towers[destination].push(disc);

    // Put discs again on top.
    hanoi_towers(towers, N-1, support, destination);
}

/*
** Fibonacci problem (or how to compute a sequence of integers where F(i) = 
**  F(i-1) + F(i-2), putting F(0) = 0 and F(1) = 1).
** A top-down dynamic solution costs O(N) because it stores the partial 
**  solutions computed so far.
** Alternatively, the Binet formula (theta^N)/sqrt(5) approximates F(N), where 
**  theta is the golden ratio (1,618).
*/
int fibonacci(const unsigned N)
{
    std::vector<unsigned> series(N+1, 0);
    series[1] = 1; // Error if N == 0.

    for (auto i = 2; i <= N; i++)
    {
        // O(1) space using only prev_1 and prev_2.
        series[i] = series[i-1] + series[i-2];
    }

    return series[N];
}

/*
** Knapsack problem (or how to fill a sack maximising the total value of the 
**  items in it). Two variants:
**  - unbounded, if each item can be taken infinite time;
**  - bounded (or 0-1), if each item can be taken a fixed amount of time.
** Dynamic Programming solution: the solution of a sack of size M' is the base 
**  for a sack of size M, where M>M'.
*/
void unbounded_knapsack(std::vector<int>& items, std::vector<int>& sacks, int M)
{
    // Assume:
    // - init sacks(M+1, -1); sacks[0]=0;
    // - init items<value> ordered by decreasing value and value==size;
    // - there is always a solution.

    if (M == 0)
    {
        return;
    }

    for (auto it = items.begin(); it != items.end(); it++)
    {
        auto m = M - *it;
        if (m < 0)
        {
            continue;
        }
        if (sacks[m] == -1)
        {
            unbounded_knapsack(items, sacks, m);
        }

        int current = sacks[m] + *it;
        sacks[M] = std::max(sacks[M], current);
    }
}