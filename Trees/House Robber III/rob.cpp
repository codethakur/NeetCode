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
public:
    int rob(TreeNode* root) {
        std::vector<int> result = dfs(root);
        return std::max(result[0], result[1]);
    }
    private:
    std::vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        std::vector<int> leftPair = dfs(root->left);
        std::vector<int> rightPair = dfs(root->right);
        int withroot = root->val + leftPair[1] + rightPair[1];
        int withoutroot = std::max(leftPair[0], leftPair[1]) + std::max(rightPair[0], rightPair[1]);
        return {withroot, withoutroot};
    }
};
