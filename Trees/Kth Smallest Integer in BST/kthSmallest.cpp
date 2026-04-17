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
    std::vector<int>nodeValue;
    void solve(TreeNode* root)
    {
        if(!root) return;
        nodeValue.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        std::sort(nodeValue.begin(), nodeValue.end());
        return nodeValue[k-1];
        
    }
};
#if 0

class Solution {
public:
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

#endif
