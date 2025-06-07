#include <iostream>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to find the Lowest Common Ancestor (LCA) of two nodes n1 and n2.
Node* lca(Node* root, int n1, int n2) 
{
    // Base case: if the current node is NULL, return NULL.
    if (root == NULL)
        return NULL;

    // If the current node matches either n1 or n2, return the current node.
    // This means we've found one of the nodes we're looking for.
    if (root->data == n1 || root->data == n2)
        return root;

    // Recursively search for the LCA in the left and right subtrees.
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    // If both left and right subtrees return non-NULL, it means that
    // n1 is located in one subtree and n2 is located in the other.
    // Therefore, the current node is the LCA.
    if (leftAns != NULL && rightAns != NULL)
        return root;

    // If only the left subtree has returned a non-NULL result,
    // it means both n1 and n2 are located in the left subtree.
    // Hence, the LCA is in the left subtree.
    if (leftAns != NULL)
        return leftAns;

    // If only the right subtree has returned a non-NULL result,
    // it means both n1 and n2 are located in the right subtree.
    // Hence, the LCA is in the right subtree.
    if (rightAns != NULL)
        return rightAns;

    // If both subtrees have returned NULL, it means neither n1 nor n2
    // were found in either subtree. Therefore, return NULL.
    return NULL;
}

// Driver code to test the LCA function.
int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    //        / \
    //       6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    int n1 = 6, n2 = 7;
    Node* lcaNode = lca(root, n1, n2);

    if (lcaNode != NULL)
        std::cout << "LCA of " << n1 << " and " << n2 << " is: " << lcaNode->data << std::endl;
    else
        std::cout << "LCA not found." << std::endl;

    return 0;
}
