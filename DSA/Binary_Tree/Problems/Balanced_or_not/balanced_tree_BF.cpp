//Tree is balanced or not (Brute Force Approach)
#include <iostream>
#include <algorithm> // For std::max and std::abs

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Function to calculate the height of a tree
int height(Node* root) {
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = std::max(left, right) + 1;
    return ans;
}

// Function to check if a tree is balanced
bool isBalanced(Node* root) {
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return 1;
    }
    else{
        return false;
    }
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root)) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
