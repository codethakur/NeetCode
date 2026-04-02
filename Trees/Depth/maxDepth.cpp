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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        std::stack<std::pair<TreeNode*, int>>rootDepth;
        rootDepth.push({root, 1});

        int maxAns = 0;

        while(!rootDepth.empty())
        {
            auto[curr, currMax] = rootDepth.top();
            rootDepth.pop();

            maxAns = std::max(maxAns, currMax);
            if(curr->left) rootDepth.push({curr->left, currMax+1});
            if(curr->right) rootDepth.push({curr->right, currMax+1});
        }
        return maxAns;
    }
};
#if 0
class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(!root) return 0;

       return 1+max(maxDepth(root->left), maxDepth(root->right));


    }
};
#endif
