// Given the root of a binary tree, return the level order traversal of its 
//  nodes' values. (i.e., from left to right, level by level).
// Input: root = [3,9,20,null,null,15,7] Output: [[3],[9,20],[15,7]].

#include <vector>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    void recursive_solution(TreeNode* root, int level, vector<vector<int>>& result)
    {
        if (root == nullptr)
        {
            return;
        }

        // Pre-order visit.
        if (result.size() <= level)
        {
            result.emplace_back();
        }
        result[level].push_back(root->val);

        // Children.
        recursive_solution(root->left, level+1, result);
        recursive_solution(root->right, level+1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;

        // Needed to not call recursively levelOrder() that returns a vector 
        //  each time: time and memory consuming!
        recursive_solution(root, 0, result);

        return result;
    }
};