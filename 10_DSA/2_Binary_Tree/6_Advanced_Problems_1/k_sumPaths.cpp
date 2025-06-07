#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void solve(Node* root, int k, int &count, std::vector<int> path) 
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    // Recurse on the left subtree
    solve(root->left, k, count, path);

    // Recurse on the right subtree
    solve(root->right, k, count, path);

    // Check for k-sum paths
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == k)
            count++;
    }

    path.pop_back();
}

int kSumTree(Node* root, int k) {
    std::vector<int> path;
    int count = 0;

    solve(root, k, count, path);
    return count;
}


// Driver code to test the LCA function.
int main() {
    // Tree structure:
    //            1
    //          /   \
    //         3     -1
    //        / \   /  \
    //       2   1 4    5
    //          /  / \   \
    //         1  1   2   6

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    int k = 5;
    int count = kSumTree(root, k);
    std::cout<< count <<std::endl;

    return 0;
}

