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

 //2. Iterative Depth First Search
#if 0
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }

        return res;
    }
};

 //3. Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        std::vector<int>res;
       
       while(curr)
       {
            if(!curr->left)
            {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* pre = curr->left;
                while(pre->right && pre->right != curr)
                {
                    pre = pre->right;
                }
                if(!pre->right)
                {
                    pre->right=curr;
                    curr = curr->left;
                }else{
                    pre->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
       }
       return res;

        
    }
};
#endif
