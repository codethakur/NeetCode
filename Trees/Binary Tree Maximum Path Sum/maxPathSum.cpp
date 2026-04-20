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
    long long maxVal = LLONG_MIN;

    long long dfs(TreeNode* root) {
        if (!root) return 0;                              // Line A

        long long L = max(0LL, dfs(root->left));          // Line B — clamp negatives
        long long R = max(0LL, dfs(root->right));         // Line C — clamp negatives

        maxVal = max(maxVal, L + root->val + R);          // Line D — path THROUGH root
        return root->val + max(L, R);                     // Line E — best arm going UP
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return (int)maxVal;
    }
};
