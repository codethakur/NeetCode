/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, std::vector<int>&data)
    {
        if(!root) return;
        data.push_back(root->val);
        dfs(root->left, data);
        dfs(root->right, data);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>data;
        dfs(root, data);
        return data;
    }
};
