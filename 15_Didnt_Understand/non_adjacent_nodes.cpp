#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to solve the problem, returns a pair of integers
// The first integer in the pair represents the maximum sum including the current node
// The second integer in the pair represents the maximum sum excluding the current node
std::pair<int, int> solve(Node* root) {
    
    // Base case: If the current node is NULL, return a pair of zeros
    if (root == NULL)
        return std::make_pair(0, 0);

    // Recursively solve the problem for the left subtree
    std::pair<int, int> left = solve(root->left);

    // Recursively solve the problem for the right subtree
    std::pair<int, int> right = solve(root->right);

    // Initialize a pair to store the answer for the current node
    std::pair<int, int> ans;

    // Calculate the maximum sum when including the current node:
    // root->data + sum excluding the left child + sum excluding the right child
    ans.first = root->data + left.second + right.second;

    // Calculate the maximum sum when excluding the current node:
    // max sum of either including or excluding the left child +
    // max sum of either including or excluding the right child
    ans.second = std::max(left.first, left.second) + std::max(right.first, right.second);

    // Return the pair of results for the current node
    return ans;
}


int getMaxSum(Node* root)
{
    std::pair<int,int> ans = solve(root);
    return std::max(ans.first, ans.second);
}

int main() {
    // Tree structure:
    //            1
    //          /   \
    //         2     3
    //        /     /  \
    //       4     5    6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);

    int ans = getMaxSum(root);
    std::cout<< ans <<std::endl;

    return 0;

//       10
//      /  \
//     1    2
//    / \    \
//   3   4    5

}

