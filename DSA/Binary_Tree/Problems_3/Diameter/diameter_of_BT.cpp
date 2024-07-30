#include <iostream>
#include <algorithm> // for std::max

// Definition of a binary tree node
struct node {
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to calculate diameter and height at the same time
int diameterUtil(node* root, int &diameter) 
{
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    }

    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update the diameter if the current path is larger
    diameter = std::max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return std::max(leftHeight, rightHeight) + 1;
}

// Wrapper function to initialize diameter and call the utility function
int diameter(node* root) 
{
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

// Example usage
int main() {
    // Creating a simple binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    std::cout << "Diameter of the tree: " << diameter(root) << std::endl;

    return 0;
}
