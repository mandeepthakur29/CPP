//Sum of Long root to leaf path
#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to solve the problem recursively
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen)
{
    // Base case: if the current node is NULL (i.e., we've reached a leaf or an empty tree)
    if(root == NULL)
    {
        // Check if the current path length is greater than the maximum length found so far
        if(len > maxLen)
        {
            maxLen = len;    // Update the maximum length
            maxSum = sum;    // Update the maximum sum with the sum of the current path
        }
        // If the current path length is equal to the maximum length
        else if(len == maxLen)
        {
            maxSum = std::max(sum, maxSum);  // Update the maximum sum to the larger of the current sum or the existing maximum sum
        }   
        return;  // Return since there's no more to process in this path
    }

    // Add the current node's data to the path sum
    sum = sum + root->data;

    // Recur for the left child, increasing the path length by 1
    solve(root->left, sum, maxSum, len + 1, maxLen);

    // Recur for the right child, increasing the path length by 1
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node* root)
{
    int len = 0;       // Initialize the current path length
    int maxLen = 0;    // Initialize the maximum path length found so far

    int sum = 0;       // Initialize the current path sum
    int maxSum = INT_MIN;  // Initialize the maximum path sum (using INT_MIN to ensure any path sum will be larger)

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}


int main() {
    // Constructing the following binary tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //             \
    //              9

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    int result = sumOfLongRootToLeafPath(root);

    std::cout <<result << std::endl;

    return 0;
}