#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

std::vector<int> zigZagTraversal(Node* root) {
    std::vector<int> result;
    if (root == NULL)
        return result;

    std::queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            // Normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // Direction change
        leftToRight = !leftToRight;

        for (int i : ans) {
            result.push_back(i);
        }
    }

    return result;
}

// Helper function to print the result
void printResult(const std::vector<int>& result) {
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Example usage
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
    printResult(result);

    return 0;
}
