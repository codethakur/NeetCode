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
    bool isTrue(TreeNode* root, long left, long right) {
        if (!root) return true;

        if (!(left < root->val && root->val < right)) {
            return false;
        }

        return isTrue(root->left, left, root->val) &&
               isTrue(root->right, root->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isTrue(root, LONG_MIN, LONG_MAX);
    }
};
