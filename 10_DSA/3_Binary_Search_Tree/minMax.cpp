#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to find the minimum node in the BST
Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL; // The tree is empty
    }

    Node* current = root;
    // The minimum value will always be in the leftmost node
    while (current->left != NULL) {
        current = current->left;
    }
    return current; // The leftmost node is the minimum
}

// Function to find the maximum node in the BST
Node* findMax(Node* root) {
    if (root == NULL) {
        return NULL; // The tree is empty
    }

    Node* current = root;
    // The maximum value will always be in the rightmost node
    while (current->right != NULL) {
        current = current->right;
    }
    return current; // The rightmost node is the maximum
}

int main() {
    // Creating a simple BST for demonstration
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Finding the minimum node in the BST
    Node* minNode = findMin(root);
    if (minNode != NULL) {
        std::cout << "Minimum node in BST: " << minNode->data << std::endl;
    }

    // Finding the maximum node in the BST
    Node* maxNode = findMax(root);
    if (maxNode != NULL) {
        std::cout << "Maximum node in BST: " << maxNode->data << std::endl;
    }

    return 0;
}
