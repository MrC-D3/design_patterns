#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int max_j = matrix[0].size();
        vector<int> prev_sides(max_j, 0);
        vector<int> current_sides(max_j, 0);
        int max_side = 0;

        // Line 0.
        for (int j = 0; j < max_j; j++)
        {
            if (matrix[0][j] == '1')
            {
                current_sides[j] = 1;
                max_side = max(max_side, current_sides[j]);
            }
        }

        // Case 03: 
        // [["1","1","1","1","1","1","1","1"],
        //  ["1","2","2","2","2","2","2","0"],
        //  ["1","2","3","3","3","3","3","0"],
        //  ["1","2","3","4","4","0","0","0"],
        //  ["0","1","2","3","4","0","0","0"]]
        for (int i = 1; i < matrix.size(); i++)
        {
            swap(current_sides, prev_sides);

            if (matrix[i][0] == '1')
            {
                current_sides[0] = 1;
                max_side = max(max_side, current_sides[0]);
            }
            else
            {
                current_sides[0] = 0;
            }

            for (int j = 1; j < max_j; j++)
            {
                if (matrix[i][j] == '0')
                {
                    current_sides[j] = 0;
                    continue;
                }

                current_sides[j] = min({prev_sides[j], prev_sides[j-1], current_sides[j-1]}) + 1;

                max_side = max(max_side, current_sides[j]);
            }

            for(auto a : current_sides)
                cout << a;
            cout << endl;
            cout << "After line X: " << max_side << endl;
        }

        return max_side*max_side;
    }


    // O(M×N).
    int maximalSquare_v2(vector<vector<char>>& matrix) 
    {
        // Store in [i][j] the greatest square's side that ends in [i][j].
        vector<vector<int>> sides(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_side = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    sides[i][j] = 0;
                    continue;
                }

                if ((i-1 < 0) || (j-1 < 0))
                {
                    sides[i][j] = 1;
                }
                else
                {
                    sides[i][j] = min({sides[i-1][j], sides[i][j-1], sides[i-1][j-1]}) + 1;
                }

                max_side = max(max_side, sides[i][j]);
            }
        }

        return max_side*max_side;
    }


    // O(M∗N∗Min(M,N))
    int maximalSquare_v1(vector<vector<char>>& matrix) 
    {
        int max_j = matrix[0].size();
        int max_side = 0;
        int side_limit = min(max_j, (int)matrix.size());

        for (int i = 0; i < matrix.size() && max_side < side_limit && max_side < matrix.size()-i; i++)
        {
            for (int j = 0; j < max_j && max_side < side_limit && max_side < max_j-j; j++)
            {
                int next_row = i;
                int next_column = j;
                bool keep_going = true;
                int side = 0;

                do
                {
                    // Check new column.
                    for (int h = i; h <= next_row; h++)
                    {
                        if (matrix[h][next_column] == '0')
                        {
                            keep_going = false;
                            break;
                        }
                    }
                    // Check new row.
                    for (int h = j; h <= next_column && keep_going; h++)
                    {
                        if (matrix[next_row][h] == '0')
                        {
                            keep_going = false;
                            break;
                        }
                    }
                    //
                    if (keep_going)
                    {
                        side += 1;
                        max_side = max(max_side, side);
                        next_row += 1;
                        next_column += 1;
                        if(next_row >= matrix.size() || next_column >= max_j)
                        {
                            keep_going = false;
                        }
                    }
                } while (keep_going);
            }
        }
    
        return max_side*max_side;
    }
};

int main()
{
    // Case 01.
    vector<vector<char>> input{{'1','1','1','1','0'}, {'1','1','1','1','0'}, {'1','1','1','1','1'}, {'1','1','1','1','1'}, {'0','0','1','1','1'}};
    Solution s;
    //cout << s.maximalSquare(input) << endl;

    // Case 02.
    vector<vector<char>> input2{{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
    //cout << s.maximalSquare(input2) << endl;

    // Case 03.
    vector<vector<char>> input3{{'1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','0'},
    {'1','1','1','1','1','0','0','0'},{'0','1','1','1','1','0','0','0'}};
    cout << s.maximalSquare(input3) << endl;

    return 0;
}
