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
#include <list>
#include <vector>
#include <stack>
#include <array>

// Array nodes[N] is initialized so that nodes[a] = a.
// Find: for each (i, j) in input, check if nodes[i] == nodes[j]; if not, Union.
//  Quick-find because I can find immediately the set each node belongs to.
// Union: if nodes[k] == nodes[j], make nodes[k] = i.
//  Slow-union because requires to read the whole array. 
// Worst case: read the whole array for all the M couples, so the cost is M*N.
void quick_find(std::vector<int>& nodes, int N, int i, int j)
{
    // Find.
    if(nodes[i] == nodes[j])
        return;

    // Union.
    // For all the M couples, it reads all the N values of the array.
    for(int k = 0; k < N; k++)
    {
        if(nodes[k] == nodes[j])
            nodes[k] = i;
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
    nodes[l] = k;
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

    // Weighted union.
    // Worst case: same size, because no advantages.
    if(sizes[k] > sizes[l])
    {
        nodes[l] = k;
    }
    else
    {
        nodes[k] = l;
    }
}

// ... all the weighted quick-union steps, but once I have the roots, I iterate 
//  over the array to make all the nodes children of the root.
void weighted_quick_union_with_path_compression(std::vector<int>& nodes, 
  std::vector<int>& sizes, int i, int j)
{
    // Find.
    int rootA;
    for(rootA = i; rootA != nodes[rootA]; rootA = nodes[rootA]);
    int rootB;
    for(rootB = j; rootB != nodes[rootB]; rootB = nodes[rootB]);

    // Weighted union.
    // Worst case: same size, because no advantages.
    int newRoot;
    int start;
    if(sizes[rootA] > sizes[rootB])
    {
        nodes[rootB] = rootA;
        newRoot = rootA;
        start = j;
    }
    else
    {
        nodes[rootA] = rootB;
        newRoot = rootB;
        start = i;        
    }
    
    // Path compression.
    for(int h = start; h != nodes[i]; )
    {
        int next = nodes[i];
        nodes[i] = newRoot;
        i = next;
    }
}

// ... all the weighted quick union steps, but while I check for the roots I 
//  link the current node to its grandparent (i.e. id[i] = id[ id[i] ]).
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

    // Weighted union.
    // Worst case: same size, because no advantages.
    int newRoot;
    if(sizes[rootA] > sizes[rootB])
    {
        nodes[rootB] = rootA;
    }
    else
    {
        nodes[rootA] = rootB;      
    }
}

// TESTS.
int main()
{
    // 01.
    quick_find();
    // 02.
    quick_union();
    // 03.
    weighted_quick_union();
    // 04.
    weighted_quick_union_with_path_compression();
    // 05.
    weighted_quick_union_with_path_compression_by_halving();

    return 0;
}