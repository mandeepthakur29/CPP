#include <iostream>

// Define the node class for the tree
class node {
public:
    int data;       // Data held by the node
    node* left;     // Pointer to the left child node
    node* right;    // Pointer to the right child node

    // Constructor to initialize a new node with a given value
    node(int d) {
        this->data = d;    // Set the node's data
        this->left = NULL; // Initialize the left child pointer to NULL
        this->right = NULL;// Initialize the right child pointer to NULL
    }
};

// Function to build the tree recursively
node* buildTree(node* root) {
    std::cout << "Enter Data: ";
    int data;
    std::cin >> data; // Take data input from the user

    // If data is -1, this indicates that there should be no node here
    if (data == -1) {
        return NULL; // Return NULL to signify no node
    }

    // Create a new node with the given data
    root = new node(data);

    // Prompt for left child data and build the left subtree recursively
    std::cout << "Enter data for inserting in left of: " << data << std::endl;
    root->left = buildTree(root->left);

    // Prompt for right child data and build the right subtree recursively
    std::cout << "Enter data for inserting in right of: " << data << std::endl;
    root->right = buildTree(root->right);

    // Return the created node (root of this subtree)
    return root;
}

int main() {
    node* root = NULL; // Initialize the root pointer to NULL (empty tree)

    // Build the tree starting from the root
    root = buildTree(root);

    return 0; // End of program
}
