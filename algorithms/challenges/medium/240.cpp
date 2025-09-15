// Write an efficient algorithm that searches for a value target in an m x n 
//  integer matrix matrix. This matrix has the following properties: 
//  - Integers in each row are sorted in ascending from left to right.
//  - Integers in each column are sorted in ascending from top to bottom.
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[
//  18,21,23,26,30]], target = 5.

#include <vector>


using namespace std;

class Solution 
{
public:
    // O(M+N)
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i = 0;
        int j = matrix[0].size() - 1;
        while ((i < matrix.size()) && (j >= 0))
        {
            if (target < matrix[i][j])
            {
                j -= 1;
            }
            else if (target > matrix[i][j])
            {
                i += 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    bool searchMatrix_2(vector<vector<int>>& matrix, int target) 
    {
        bool found{false};

        int max_i = matrix.size() - 1;
        int max_j = matrix[0].size() - 1;
        for (int i = 0; (i <= max_i) && (!found); i++)
        {
            for (int j = max_j; j >= 0 ; j--)
            {
                if (target < matrix[i][j])
                {
                    max_j -= 1;
                }
                else if ((target > matrix[i][j]) && (j == max_j))
                {
                    break;
                }
                else if (target == matrix[i][j])
                {
                    found = true;
                    break;
                }
            }
        }

        return found;
    }

    bool searchMatrix_v1(vector<vector<int>>& matrix, int target) 
    {
        bool found{false};

        int j = 1;
        for (int i = 0; i < matrix.size() && j != 0; i++)
        {
            for (j = 0; j < matrix[i].size(); j++)
            {
                if (target == matrix[i][j])
                {
                    found = true;
                    break;
                }
                else if (target < matrix[i][j])
                {
                    break;
                }
            }
        }

        return found;
    }
};