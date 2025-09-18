// Connectivity problem (or Union-Find algorithm):
//  given a list of couples, tell if each couple creates a new connection 
//  between the elements of the couple or not; e.g.: [(a,b), (b,c)] means there
//  are connections: a-b, b-c but also a-c, so the couple a-c won't create a new
//  connection.
// General solution:
//  every element is part of a group of connected elements, so – for each couple
//  – first find() the group each element of the couple belongs to and then – if
//  the groups are different – union() the groups, because it means there is a 
//  new connection.

#include <iostream>
#include <vector>
#include <numeric> // For std::iota().
#include <random> // For std::mt19937.
#include <chrono>

// Vector nodes[N] is initialized so that nodes[a] = a.
// Find: 
// - for each (i, j) in input, check if nodes[i] == nodes[j]; 
// - if not... 
// Union:
// - nodes[k] = nodes[i], for each nodes[k] == nodes[j].
// Quick-find because you can find immediately the set each node belongs to.
// Slow-union because requires to read the whole array for each couples. 
// Worst case: read the whole array for all the M couples, so the cost is M*N.
void quick_find(std::vector<int>& nodes, int i, int j)
{
    // Find.
    if(nodes[i] == nodes[j])
        return;

    // Union.
    // Store the current value of nodes[j] before it can be overwritten.
    int old_id = nodes[j];
    for(int k = 0; k < nodes.size(); k++)
    {
        if(nodes[k] == old_id)
        {
            nodes[k] = nodes[i];
        }
    }
}

// Array nodes[N] is initialized so that nodes[a] = a.
// Find: 
// - for each (i, j), if not nodes[i] == i; repeat with i = nodes[i] till true;
// - do the same for j;
// - finally, check if nodes[i] == nodes[j] and if not, Union.
// Slow-find because of the iteration to find the “set root” of both (i, j).
// Union: make nodes[j] equale to the CURRENT value of i.
//  Quick-union because requires to just change one value in the array.
// Worst case: 
// - N numbers and N-1 couples like (1,2), (2,3), …, (N-1, N); 
// - so Find performs 0 + 1 + … + N-2 = (N-2)(N-1)/2 operations in total and
//  (N-2)(N-1)/2 * 1/(N-1) = (N-2)/2 on average for each couple;
// Even worse case: M > N, so if more couples than number, cost at least M*N/2.
// Cost expressed by "sum of power 1": C_N = C_(N-1) + N = N(N+1)/2.
void quick_union(std::vector<int>& nodes, int i, int j)
{
    // Find.
    // Worst case: couples like (0,1) (1,2) (2,3) (3,4) (4,5) (5,6) (6,7) ...
    int k;
    for(k = i; k != nodes[k]; k = nodes[k]);
    int l;
    for(l = j; l != nodes[l]; l = nodes[l]);

    // Union.
    nodes[l] = k; // Done even when unnecessary, e.g. k == l.
}

// Array size[N] = {1}, where size[k] contains how many nodes have k as root.
// Find: 
// - all the steps of the Quick-Union algorithm, but...
// Union:
// - if size[i] > size[j], the i-set includes the j-set, otherwise the opposite.
// Worst case: union between 2 leafs of 2 trees of the same size 2^H.
void weighted_quick_union(std::vector<int>& nodes, std::vector<int>& sizes, 
  int i, int j)
{
    // Find.
    int k;
    for(k = i; k != nodes[k]; k = nodes[k]);
    int l;
    for(l = j; l != nodes[l]; l = nodes[l]);

    // No Union if same root.
    if (k == l)
    {
        return ;
    }

    // Weighted union.
    // Worst case: if same size, because no advantages.
    if(sizes[k] > sizes[l])
    {
        nodes[l] = k;
        sizes[k] += sizes[l];
    }
    else
    {
        nodes[k] = l;
        sizes[l] += sizes[k];
    }
}

// Same steps of the Weighted Quick Union, plus a final step: all the nodes in 
//  the small group become children of the root in the big group.
void weighted_quick_union_with_path_compression(std::vector<int>& nodes, 
  std::vector<int>& sizes, int i, int j)
{
    // Find.
    int rootA;
    for(rootA = i; rootA != nodes[rootA]; rootA = nodes[rootA]);
    int rootB;
    for(rootB = j; rootB != nodes[rootB]; rootB = nodes[rootB]);

    // No Union if rootA == rootB.
    if (rootA == rootB)
    {
        return;
    }

    // Weighted union.
    // Worst case: if same size, because no advantages.
    int newRoot;
    int start;
    if(sizes[rootA] > sizes[rootB])
    {
        nodes[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
        newRoot = rootA;
        start = j;
    }
    else
    {
        nodes[rootA] = rootB;
        sizes[rootB] += sizes[rootA];
        newRoot = rootB;
        start = i;        
    }
    
    // Path compression.
    for(int h = start; h != nodes[h]; )
    {
        int next = nodes[h];
        nodes[h] = newRoot;
        h = next;
    }
}

// Find: 
// - while checking for the root, promote a node as his grandpa's child.
// Union:
// - if size[i] > size[j], the i-set includes the j-set, otherwise the opposite.
// Worst case: union between 2 leafs of 2 trees of the same size 2^H.
void weighted_quick_union_with_path_compression_by_halving(
  std::vector<int>& nodes, std::vector<int>& sizes, int itemA, int itemB)
{
    // Find.
    int rootA;
    for(rootA = itemA; rootA != nodes[rootA]; rootA = nodes[rootA]);
    {
        nodes[rootA] = nodes[ nodes[rootA] ];
    }
    int rootB;
    for(rootB = itemB; rootB != nodes[rootB]; rootB = nodes[rootB])
    {
        nodes[rootB] = nodes[ nodes[rootB] ];
    }

    // No Union if rootA == rootB.
    if (rootA == rootB)
    {
        return;
    }

    // Weighted union.
    // Worst case: if same size, because no advantages.
    if(sizes[rootA] > sizes[rootB])
    {
        nodes[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
    }
    else
    {
        nodes[rootA] = rootB;
        sizes[rootB] += sizes[rootA];    
    }
}

// TESTS.
int main()
{
    // Constants.
    constexpr uint N = 100;
    constexpr uint couples_number = 200;

    // Init nodes.
    std::vector<int> nodes(N);
    // Fill a container with increasing values starting from 0.
    std::iota(nodes.begin(), nodes.end(), 0);

    // Random samples.
    std::mt19937 random_number_engine; // Mersenne-Twister random number engine.
    std::random_device random_number_generator; // Hardware-based true random.
    random_number_engine.seed(random_number_generator()); // Uses /dev/urandom.
    // Better than just %N because it uses rejection sampling: discard 
    //  everything greater than MAX_INT/N*N (MAX_INT/N keeps only the int part).
    std::uniform_int_distribution<int> uniform_distribution(0, N - 1);
    // Finally build the sample pairs.
    std::vector<std::pair<int, int>> pairs;
    // Worst-case sccenario: pairs.emplace_back(i, i + 1);
    for(auto i = 0; i < couples_number; i++) 
    {
        int a = uniform_distribution(random_number_engine);
        int b = uniform_distribution(random_number_engine);
        if (a != b) 
        {
            pairs.emplace_back(a, b);
        }
    }

    // 01: Quick-Find performance.
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto pair : pairs)
        {
            quick_find(nodes, pair.first, pair.second);
        }
        auto end = std::chrono::high_resolution_clock::now();
        // Less verbose alternative: std::chrono::duration<double, std::milli>().
        auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(
        end-start);
        auto time_ms = time_us.count() / 1000.0;

        std::cout << "Quick-Find: " << time_ms << " ms." << std::endl;
    }

    // 02: Quick-Union performance.
    std::iota(nodes.begin(), nodes.end(), 0);
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto pair : pairs)
        {
            quick_union(nodes, pair.first, pair.second);
        }
        auto end = std::chrono::high_resolution_clock::now();
        // Less verbose alternative: std::chrono::duration<double, std::milli>().
        auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(
        end-start);
        auto time_ms = time_us.count() / 1000.0;

        std::cout << "Quick-Union: " << time_ms << " ms." << std::endl;
    }

    // 03: Weighted Quick-Union performance.
    std::iota(nodes.begin(), nodes.end(), 0);
    {
        // Init sizes with N values at 1.
        std::vector<int> sizes(N, 1);

        auto start = std::chrono::high_resolution_clock::now();
        for (auto pair : pairs)
        {
            weighted_quick_union(nodes, sizes, pair.first, pair.second);
        }
        auto end = std::chrono::high_resolution_clock::now();
        // Less verbose alternative: std::chrono::duration<double, std::milli>().
        auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(
        end-start);
        auto time_ms = time_us.count() / 1000.0;

        std::cout << "Weighted Quick-Union: " << time_ms << " ms." << std::endl;
    }

    // 04: Weighted Quick-Union with Path Compression
    std::iota(nodes.begin(), nodes.end(), 0);
    {
        // Init sizes with N values at 1.
        std::vector<int> sizes(N, 1);

        auto start = std::chrono::high_resolution_clock::now();
        for (auto pair : pairs)
        {
            weighted_quick_union_with_path_compression(nodes, sizes, pair.first,
              pair.second);
        }
        auto end = std::chrono::high_resolution_clock::now();
        // Less verbose alternative: std::chrono::duration<double, std::milli>().
        auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(
        end-start);
        auto time_ms = time_us.count() / 1000.0;

        std::cout << "W.Q.U. with Path Compression: " << time_ms << " ms.\n";
    }

    // 05: Weighted Quick Union with Path Compression by Halving.
    std::iota(nodes.begin(), nodes.end(), 0);
    {
        // Init sizes with N values at 1.
        std::vector<int> sizes(N, 1);

        auto start = std::chrono::high_resolution_clock::now();
        for (auto pair : pairs)
        {
            weighted_quick_union_with_path_compression_by_halving(nodes, sizes, 
              pair.first, pair.second);
        }
        auto end = std::chrono::high_resolution_clock::now();
        // Less verbose alternative: std::chrono::duration<double, std::milli>().
        auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(
        end-start);
        auto time_ms = time_us.count() / 1000.0;

        std::cout << "W.Q.U. with P.C. by Halving: " << time_ms << " ms.\n";
    }

    // TODO:
    // - check time also for worst case (i.e. 1-2, 2-3, 3-4, 4-5, 5-6, ...);
    // - DRY (each test does the same thing, Don't Repeat Yourself).

    return 0;
}