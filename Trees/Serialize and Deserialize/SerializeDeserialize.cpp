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

class Codec {
    TreeNode* build(queue<string>& q) {
        string val = q.front(); q.pop(); 
        if (val == "N") return nullptr;        
        TreeNode* node = new TreeNode(stoi(val));
        node->left  = build(q);
        node->right = build(q);
        return node;                             
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string left  = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val)+","+left+","+right;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ','))
            q.push(token);
        return build(q);   
    }
};
