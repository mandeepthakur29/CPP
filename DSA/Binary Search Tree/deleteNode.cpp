#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to find the minimum value node in a BST
Node* minVal(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given value from the BST
Node* deleteFromBST(Node* root, int val) {
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // If the node to be deleted is found
    if (root->data == val) {
        // Case 1: Node with 0 children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root; // Free the memory
            return NULL; // Return NULL to parent node
        }

        // Case 2: Node with 1 child (left child only)
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left; // Store the left child
            delete root; // Delete the current node
            return temp; // Return the left child to parent node
        }

        // Case 2: Node with 1 child (right child only)
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right; // Store the right child
            delete root; // Delete the current node
            return temp; // Return the right child to parent node
        }

        // Case 3: Node with 2 children
        if (root->left != NULL && root->right != NULL) {
            // Find the minimum value node in the right subtree (inorder successor)
            int mini = minVal(root->right)->data;
            root->data = mini; // Replace the current node's data with the minimum value
            // Recursively delete the inorder successor
            root->right = deleteFromBST(root->right, mini);
            return root; // Return the root after modification
        }
    }

    // If the value to be deleted is smaller, recurse on the left subtree
    else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
    }
    // If the value to be deleted is larger, recurse on the right subtree
    else {
        root->right = deleteFromBST(root->right, val);
    }

    // Return the root node after any potential changes
    return root;
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

    int val = 35; // Value to delete

    // Call the delete function
    Node* ans = deleteFromBST(root, val);

    return 0;
}
