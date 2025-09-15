
// Forward may be more efficient.
int logarithm_forward(int N)
{
    int result, i;

    for(result = 0, i = 1; i <= N; result += 1, i += i);

    return i;
}

// Find the prime numbers till N.
void sieve_of_eratosthenes(int array[N]) // Sieve means setaccio in Italian.
{
    for(int i = 2; i < N; i++)
    {
        if( array[i] == 1)
        {
            for(int j = i; j < N; j += j)
            {
                array[j] = 0;
            }
        }
    }
}

int josephus_problem(std::list<int> elements, int step) // 5, 2: [1, 2, 3, 4, 5]
{
    auto it = elements.begin();

    for(int size = elements.size(); size != 1; size -= 1)
    {
        for(int j = 1; j < step; j++)
        {
            it++;
            if(it == elements.end())
            {
                it = elements.begin();
            }
        }

        auto tmp = it;
        it++;
        elements.erase(tmp); // [1, 3, 4, 5]; [1, 2, 5]; [2, 5]; [2]
    }

    return elements.back();
}

// Both algorithms return correct_result+1 for N%2==0.
int logarithm_backward(int N)
{
    int result, i;

    for(result = 0, i = N; i != 0; result += 1, i /= 2);

    return i;
}


int main()
{
    std::cout << "Hello World!" << std::endl;

    return 0;
}