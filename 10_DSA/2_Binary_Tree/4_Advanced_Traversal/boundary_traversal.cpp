#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void traverseLeft(Node* root, std::vector<int> &ans) {
    // Base case: If the node is NULL or it's a leaf node, return.
    // We do not include leaf nodes in the left boundary traversal.
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    // Add the current node's data to the boundary list as it's part of the left boundary.
    ans.push_back(root->data);

    // If the left child exists, recursively traverse the left child.
    if (root->left) {
        traverseLeft(root->left, ans);
    }
    // If the left child doesn't exist, but the right child does, traverse the right child.
    // This ensures that we continue down the boundary, even if the left child is missing.
    else {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, std::vector<int> &ans) {
    // Base case: If the node is NULL, return.
    if (root == NULL) {
        return;
    }

    // If the node is a leaf node (no left or right children), add its data to the list.
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    // Recursively traverse the left subtree to find leaf nodes.
    traverseLeaf(root->left, ans);

    // Recursively traverse the right subtree to find leaf nodes.
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, std::vector<int> &ans) {
    // Base case: If the node is NULL or it's a leaf node, return.
    // We do not include leaf nodes in the right boundary traversal.
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    // If the right child exists, recursively traverse the right child.
    if (root->right) {
        traverseRight(root->right, ans);
    }
    // If the right child doesn't exist, but the left child does, traverse the left child.
    // This ensures that we continue down the boundary, even if the right child is missing.
    else {
        traverseRight(root->left, ans);
    }

    // Add the current node's data to the boundary list as it's part of the right boundary.
    // We add it after the recursive calls to ensure the right boundary is added in reverse order.
    ans.push_back(root->data);
}

std::vector<int> boundary(Node* root) {
    std::vector<int> ans;

    // If the tree is empty, return an empty list.
    if (root == NULL) {
        return ans;
    }
    
    // Add the root data as part of the boundary.
    ans.push_back(root->data);

    // Traverse the left boundary (excluding the leaf nodes).
    traverseLeft(root->left, ans);

    // Traverse all leaf nodes.
    // First, traverse leaf nodes in the left subtree.
    traverseLeaf(root->left, ans);
    // Then, traverse leaf nodes in the right subtree.
    traverseLeaf(root->right, ans);

    // Traverse the right boundary (excluding the leaf nodes).
    // The nodes are added in reverse order.
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   7
    //    /   / \   \
    //   8   9  10  11

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->right->right->right = new Node(11);

    std::vector<int> boundaryTraversal = boundary(root);

    // Printing the boundary traversal
    std::cout << "Boundary Traversal: ";
    for (int val : boundaryTraversal) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
