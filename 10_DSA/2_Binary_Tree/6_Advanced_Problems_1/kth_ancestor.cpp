#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* solve(Node* root, int k, int node) 
{
    // Base case: if the root is NULL, return NULL.
    if(root == NULL)
        return NULL;

    // If the current node's data matches the target node's data, return the current node.
    if(root->data == node)
    {
        return root;
    }

    // Recurse on the left subtree to find the node.
    Node* leftAns = solve(root->left, k, node);

    // Recurse on the right subtree to find the node.
    Node* rightAns = solve(root->right, k, node);

    // If the node was found in the left subtree and not in the right subtree:
    if(leftAns != NULL && rightAns == NULL)
    {
        // Decrement the distance `k`.
        k--;

        // If `k` has reached zero or less, we have found the k-th ancestor.
        if(k <= 0)
        {
            // Set `k` to a large value (INT_MAX) to indicate that we've found the ancestor.
            k = INT_MAX;

            // Return the current node as the k-th ancestor.
            return root;
        }

        // Otherwise, continue returning the found node up the recursive stack.
        return leftAns;
    }

    // If the node was found in the right subtree and not in the left subtree:
    if(leftAns == NULL && rightAns != NULL)
    {
        // Decrement the distance `k`.
        k--;

        // If `k` has reached zero or less, we have found the k-th ancestor.
        if(k <= 0)
        {
            // Set `k` to a large value (INT_MAX) to indicate that we've found the ancestor.
            k = INT_MAX;

            // Return the current node as the k-th ancestor.
            return root;
        }

        // Otherwise, continue returning the found node up the recursive stack.
        return rightAns;
    }

    // If the node wasn't found in either the left or right subtree, return NULL.
    return NULL;
}


int kthAncestor(Node* root, int k, int node) 
{
    Node* ans = solve(root, k, node);
    if(ans == NULL)
    {
        return -1;
    }

    return ans->data;
}


// Driver code to test the LCA function.
int main() {
    // Tree structure:
    //            1
    //          /   \
    //         2     3
    //        / \      
    //       4   5      

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 4;
    int ans = kthAncestor(root, k, node);
    std::cout<< ans <<std::endl;

    return 0;
}

