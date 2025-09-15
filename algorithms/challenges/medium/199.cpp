// Given the root of a binary tree, imagine yourself standing on the right side
//  of it, return the values of the nodes you can see ordered from top to 
//  bottom.
// Input: root = [1,2,3,4,null,null,null,5] Output: [1,3,4,5]

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
    void recursive_search(TreeNode* root, int level, vector<vector<int>>& nodes_by_level)
    {
        if (root == nullptr)
        {
            return;
        }

        if (nodes_by_level.size() <= level)
        {
            nodes_by_level.emplace_back();
        }
        nodes_by_level[level].push_back(root->val);

        recursive_search(root->left, level+1, nodes_by_level);
        recursive_search(root->right, level+1, nodes_by_level);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<vector<int>> nodes_by_level;
        recursive_search(root, 0, nodes_by_level);

        vector<int> result;
        for(auto& level_nodes : nodes_by_level)
        {
            result.push_back( level_nodes.back() );
        }

        return result;
    }
};