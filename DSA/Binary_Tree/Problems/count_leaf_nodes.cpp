#include <iostream>
#include <queue>

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    std::cout << "Enter Data: ";
    int data;
    std::cin >> data;

    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    std::cout << "Enter data for inserting in left of: " << data << std::endl;
    root->left = buildTree(root->left);
    std::cout << "Enter data for inserting in right of: " << data << std::endl;
    root->right = buildTree(root->right);

    return root;
}

// Function to count the number of leaf nodes in the binary tree
int countLeafNodes(node* root) 
{
    // If the root is NULL, it means the tree is empty, or we have reached a leaf node's child
    if (root == NULL) {
        return 0;
    }

    // If both left and right child pointers are NULL, this is a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count the leaf nodes in the left and right subtrees and add them
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    node* root = NULL;

    // Building the tree
    root = buildTree(root);

    // Count leaf nodes
    int leafCount = countLeafNodes(root);
    std::cout << "Number of leaf nodes: " << leafCount << std::endl;

    return 0;
}
