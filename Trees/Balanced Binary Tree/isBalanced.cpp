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
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return 1+max(height(root->left), height(root->right));

    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = height(root->left);
        int right = height(root->right);

        if(abs(left - right)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


#if 0
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*>st;
        unordered_map<TreeNode*, int> height;
        TreeNode* curr = root;
        TreeNode* visitedNode = nullptr;
        while(curr || !st.empty())
        {
            if(curr)
            {
                st.push(curr);
                curr = curr->left;
            }else
            {
                auto node = st.top();
                if(node->right && node->right != visitedNode){
                    curr = node->right;
                }else {
                    int left = node->left ? height[node->left] : 0;
                    int right = node->right ? height[node->right] : 0;

                    if(abs(left-right)>1) return false;

                    height[node] = 1 + max(left, right);
                    visitedNode = node;
                    st.pop();
                }
            }
        }
        return true;
    }
};
#endif


#if 0
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        stack<pair<TreeNode*, bool>> st;
        unordered_map<TreeNode*, int> height;
        
        st.push({root, false});

        while(!st.empty())
        {
            auto[node, visited] = st.top();
            st.pop();
            if (!node) continue;
            
            if(visited)
            {
                int left = node->left ? height[node->left] : 0;
                int right = node->right ? height[node->right] : 0;

                if(abs(left-right)>1) return false;

               height[node] = 1 + max(left, right);
            }else
            {
                st.push({node, true});
                st.push({node->left, false});
                st.push({node->right, false});
            }
        }
        return true;
    }
};

#endif
