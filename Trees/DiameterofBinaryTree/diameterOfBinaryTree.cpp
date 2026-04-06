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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftSubTree = diameterOfBinaryTree(root->left);
        int rightSubTree = diameterOfBinaryTree(root->right);
        int throughroot = maxDepth(root->left) + maxDepth(root->right);

        return max(throughroot, max(leftSubTree, rightSubTree));
    }
};


#if 0
class Solution {
    int diameter = 0;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // update diameter
        diameter = max(diameter, left + right);

        // return height
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
};
#endif
