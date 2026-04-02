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

#if 0

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            res.push_back(node->val);

            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int>res;
        TreeNode* curr = root;

        while(curr)
        {
            if(!curr->right)
            {
                res.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                TreeNode* prev = curr->right;
                while(prev->left && prev->left!=curr)
                {
                    prev = prev->left;
                }
                if(!prev->left){
                    res.push_back(curr->val);
                    prev->left = curr;
                    curr=curr->right;
                }else{
                    prev->left = nullptr;
                    curr = curr->left;
                }

            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif
