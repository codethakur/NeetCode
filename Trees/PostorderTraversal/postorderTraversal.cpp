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
    void solve(TreeNode* root, vector<int>&data)
    {
        if(!root) return;
        solve(root->left, data);
        solve(root->right, data);
        data.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int>res;
        solve(root, res);
        return res;
    }
};
