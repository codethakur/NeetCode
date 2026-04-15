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
    int dfs(TreeNode* node, int maxVal)
    {
        if(!node) return 0;

        int ans = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);
        ans +=dfs(node->left, maxVal);
        ans +=dfs(node->right, maxVal);
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
#if 0
class Solution {

public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while(!q.empty())
        {
            auto[node, maxVal] = q.front();
            q.pop();

            if(node->val >= maxVal){
                ans++;
            }
            if(node->left){
                q.push({node->left, max(maxVal, node->val)});
            }
            if(node->right){
                q.push({node->right, max(maxVal, node->val)});
            }
        }
        return ans;
    }
};

#endif
