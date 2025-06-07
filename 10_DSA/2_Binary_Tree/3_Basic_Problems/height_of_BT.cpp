//Height/Depth of Binary Tree 

#include <iostream>
#include <algorithm> // for std::max

// Definition of a binary tree node
struct node {
    int data;
    node* left;
    node* right;
    
    node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to calculate the height of the tree
int height(node* root) 
{
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return std::max(left, right)+1;
}

int main() {
    // Creating a simple binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    std::cout << "Max Height of the tree: " << height(root) << std::endl;

    return 0;
}
