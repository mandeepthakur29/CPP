#include <iostream>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

std::vector<int> zigZagTraversal(Node* root) {
    // Result vector to store the final zigzag order traversal
    std::vector<int> result;
    
    // If the tree is empty, return the empty result vector
    if (root == NULL)
        return result;

    // Queue to help with level-order traversal (BFS)
    std::queue<Node*> q;
    q.push(root);  // Start with the root node

    // Boolean flag to indicate the direction of traversal
    bool leftToRight = true;

    // Process nodes level by level
    while (!q.empty()) {
        // Get the number of nodes at the current level
        int size = q.size();

        // Temporary vector to store the current level's node values
        std::vector<int> ans(size);

        // Process each node at the current level
        for (int i = 0; i < size; i++) {
            // Get the front node from the queue
            Node* frontNode = q.front();
            q.pop();

            // Determine the position to insert the node's value in the ans vector
            // If leftToRight is true, insert at index i (normal order)
            // If leftToRight is false, insert at index size - i - 1 (reverse order)
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            // Add the left child to the queue if it exists
            if (frontNode->left)
                q.push(frontNode->left);

            // Add the right child to the queue if it exists
            if (frontNode->right)
                q.push(frontNode->right);
        }

        // Toggle the direction for the next level
        leftToRight = !leftToRight;

        // Append the current level's values to the result vector
        for (auto i : ans) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::vector<int> result = zigZagTraversal(root);

    // Print the result
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
