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

std::vector<int> topView(Node* root) {
    // Vector to store the final top view of the binary tree.
    std::vector<int> ans;

    // Base case: if the tree is empty, return an empty vector.
    if (root == NULL)
        return ans;

    // `topNode` is a map that stores the first (topmost) node encountered at each horizontal distance (hd).
    // The key is the `hd`, and the value is the node's data.
    std::map<int, int> topNode;

    // `q` is a queue used for level-order traversal (BFS). Each element in the queue is a pair:
    // - The first element is a pointer to the node.
    // - The second element is the horizontal distance (hd) of the node.
    std::queue<std::pair<Node*, int> > q;

    // Start by pushing the root node onto the queue with an initial hd = 0.
    q.push(std::make_pair(root, 0));

    // Perform a level-order traversal (BFS) of the tree.
    while (!q.empty()) {
        // Get the front element of the queue.
        std::pair<Node*, int> temp = q.front();
        q.pop();

        // Extract the node and its corresponding hd.
        Node* frontNode = temp.first;
        int hd = temp.second;

        // If no node has been recorded at this hd before, record the current node.
        // This ensures that only the topmost node at each hd is stored.
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        // If the left child exists, push it onto the queue with updated hd.
        // The left child's hd is (hd - 1).
        if (frontNode->left) {
            q.push(std::make_pair(frontNode->left, hd - 1));
        }

        // If the right child exists, push it onto the queue with updated hd.
        // The right child's hd is (hd + 1).
        if (frontNode->right) {
            q.push(std::make_pair(frontNode->right, hd + 1));
        }
    }

    // Traverse the `topNode` map (which is sorted by hd) to build the final top view.
    // This ensures that nodes are added to `ans` in the correct order from leftmost to rightmost hd.
    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    // Return the vector containing the top view of the binary tree.
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

    std::vector<int> result = topView(root);

    // Print the vertical order traversal result.
    std::cout << "Vertical Order Traversal: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}