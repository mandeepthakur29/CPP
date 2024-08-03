#include <iostream>
#include <vector>
#include <map>
#include <queue>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void solve(Node* root, std::vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}


std::vector<int> leftView(Node* root)
{
    std::vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {
    // Example to test the vertical order traversal:
    // Constructing the following binary tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //        \   \
    //         8   9

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right->right = new Node(9);

    std::vector<int> result = leftView(root);

    // Print the vertical order traversal result.
    std::cout << "left View: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}