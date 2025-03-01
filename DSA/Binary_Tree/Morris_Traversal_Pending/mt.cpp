#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void morrisTraversal(Node* root) {
    Node* current = root;

    while (current != NULL) 
    {
        if (current->left == NULL) {
            // If there is no left child, print the current node and move to the right
            std::cout << current->data << " ";
            current = current->right;
        } 
        else {
            // Find the in-order predecessor of current
            Node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current) 
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Make current as the right child of its in-order predecessor
                predecessor->right = current;
                current = current->left;
            } 
            else {
                // Revert the changes (fix the tree) and print the current node
                predecessor->right = NULL;
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    morrisTraversal(root);  // Output: 1 2 3 4 5 6 7

    return 0;
}
