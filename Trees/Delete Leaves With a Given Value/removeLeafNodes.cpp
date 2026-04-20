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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(!root->left && !root->right && root->val == target){
            return nullptr;
        }
        return root;
    }
};
#if 0
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* visited = nullptr;

        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            if (cur->right && cur->right != visited) {
                cur = cur->right;
                continue;
            }

            st.pop();
            if (!cur->left && !cur->right && cur->val == target) {
                if (st.empty()) return nullptr;

                TreeNode* parent = st.top();
                if (parent->left == cur) {
                    parent->left = nullptr;
                } else if (parent->right == cur) {
                    parent->right = nullptr;
                }
            } else {
                visited = cur;
            }

            cur = nullptr;
        }

        return root;
    }
};
#endif
