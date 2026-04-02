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
#if 0
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> data;
    if (!root) return data;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        data.push_back(node->val); // Root

        // Push right first
        if (node->right) st.push(node->right);

        // Then left
        if (node->left) st.push(node->left);
    }

    return data;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
    TreeNode* cur = root;

    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur)
                pred = pred->right;

            if (!pred->right) {
                res.push_back(cur->val);    vector<int> res;
    TreeNode* cur = root;

    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur)
                pred = pred->right;

            if (!pred->right) {
                res.push_back(cur->val); // DIFFERENCE
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return res;
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return res;
    }
};

#endif
