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
    unordered_map<int, int>inOrdMap;
    int preIndx = 0;
    TreeNode* build(vector<int>& preorder, int left, int right)
    {
        if(left>right) return nullptr;

        int rootVal = preorder[preIndx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int mid = inOrdMap[rootVal];

        root->left = build(preorder, left, mid -1);
        root->right = build(preorder, mid +1, right);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0; i<inorder.size(); i++)
        {
            inOrdMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size()-1);
    }
};
