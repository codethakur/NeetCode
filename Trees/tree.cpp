#include<iostream>
#include<vector>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(std::vector<int>& data, int& idx)
{
    // Base case
    if (idx >= data.size() || data[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    // Create node
    Node* node = new Node(data[idx++]);

    // Build left and right
    node->left = buildTree(data, idx);
    node->right = buildTree(data, idx);

    return node;
}

void printNode(Node* node)
{
    if (node == nullptr) return;

    std::cout << node->data<<" ";
    printNode(node->left);
    printNode(node->right);
   
}

int main()
{
    std::vector<int> data = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    int idx = 0;
    Node* root = buildTree(data, idx);

    printNode(root);
    printf("\n");

   return 0;
}