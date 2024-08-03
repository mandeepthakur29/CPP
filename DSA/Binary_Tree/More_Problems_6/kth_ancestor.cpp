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
    if(root == NULL)
        return NULL;

    if(root->data == node)
    {
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

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

