#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to search for a value in the BST
bool searchInBST(Node *root, int x) {
    Node *temp = root;

    while (temp != NULL) {
        // If the current node's data matches the target, return true
        if (temp->data == x)
            return true;
        
        // If the current node's data is greater than the target, go to the left subtree
        if (temp->data > x)
            temp = temp->left;
        else
            // If the current node's data is less than the target, go to the right subtree
            temp = temp->right;
    }

    // If the target value is not found in the tree, return false
    return false;
}

int main() {
    // Creating a simple BST for demonstration
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int x = 5; // Value to search for

    // Call the search function
    if (searchInBST(root, x)) {
        std::cout << x << " is found in the BST." << std::endl;
    } else {
        std::cout << x << " is not found in the BST." << std::endl;
    }

    return 0;
}
