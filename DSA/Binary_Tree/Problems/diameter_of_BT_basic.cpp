#include <iostream>
#include <algorithm> // for std::max

// Definition of a binary tree node
struct node {
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(NULL), right(NULL) {}
};

int height(node* root) 
{
    if(root == NULL){
        return -1;
    }

    int left = height(root->left);
    int right = height(root->right);

    return std::max(left, right)+1;
}

// Function to calculate diameter and height at the same time
int diameter(node* root) 
{
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = std::max(op1, std::max(op2, op3));
    return ans;
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
