// Given an m x n 2D binary grid grid which represents a map of '1's (land) and 
//  '0's (water), return the number of islands. An island is surrounded by water
//  and is formed by connecting adjacent lands horizontally or vertically. You 
//  may assume all four edges of the grid are all surrounded by water.
// Input: grid = [["1","1","1"], ["0","x","0"], ["1","1","1"]] Output: 1.

#include <vector>
#include <iostream>
#include <stack>


using namespace std;

class Solution
{
public:
    void visit_island(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';
        visit_island(grid, i, j+1);
        visit_island(grid, i, j-1);
        visit_island(grid, i+1, j);
        visit_island(grid, i-1, j);
    }

    int numIslands_v1(vector<vector<char>>& grid) 
    {
        int island_count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    island_count += 1;
                    visit_island(grid, i, j);
                }
            }
        }

        return island_count;
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int island_count = 0;
        stack<pair<int, int>> to_visit;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    island_count += 1;
                    to_visit.push({i,j});
                    while (!to_visit.empty())
                    {
                        auto land = to_visit.top();
                        to_visit.pop();
                        auto h = land.first;
                        auto k = land.second;
                        if (h < 0 || h >= grid.size() 
                          || k < 0 || k >= grid[h].size() 
                          || grid[h][k] == '0')
                        {
                            continue;
                        }

                        grid[h][k] = '0';
                        to_visit.push({h,k+1});
                        to_visit.push({h,k-1});
                        to_visit.push({h+1,k});
                        to_visit.push({h-1,k});
                    }
                }
            }
        }

        return island_count;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> input{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    cout << s.numIslands(input) << endl;
}