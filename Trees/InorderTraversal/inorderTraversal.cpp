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
    void dfs(TreeNode* root, vector<int>& data) {
        if (!root) return;

        dfs(root->left, data);      // Left
        data.push_back(root->val);  // Root
        dfs(root->right, data);     // Right
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> data;
        dfs(root, data);
        return data;
    }
};
