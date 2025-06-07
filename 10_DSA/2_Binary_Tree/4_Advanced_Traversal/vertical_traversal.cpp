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

std::vector<int> verticalOrder(Node* root) {

    // The `nodes` map stores nodes according to their horizontal distance (hd) and level (lvl).
    // It uses a map of maps where:
    // - The outer map's key is `hd` (horizontal distance).
    // - The inner map's key is `lvl` (level of the node).
    // - The value is a vector of node values present at that particular hd and lvl.

    std::map<int, std::map<int, std::vector<int> > > nodes; //map<hd, map<lvl, vector<list_of_nodes> > > nodes;

    // The `q` queue is used for performing a level-order traversal (BFS) of the tree.
    // Each element in the queue is a pair where:
    // - The first element is a pointer to a node.
    // - The second element is a pair of integers representing the node's hd and lvl.

    std::queue<std::pair<Node*, std::pair<int, int> > > q; //queue<pair<list_of_nodes, pair<hd, lvl> > > q;
    
    // `ans` is the vector that will store the final vertical order traversal of the tree.
    std::vector<int> ans;

    // Base case: if the root is NULL, return an empty vector.
    if (root == NULL) {
        return ans;
    }

    // Start by pushing the root node onto the queue with initial hd = 0 and lvl = 0.
    q.push(std::make_pair(root, std::make_pair(0, 0)));

    // Perform a level-order traversal (BFS) of the tree.
    while (!q.empty()) {
        // Get the front element of the queue.
        std::pair<Node*, std::pair<int, int> > temp = q.front();
        q.pop();

        // Extract the node and its corresponding hd and lvl from the pair.
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        // Place the node's data in the `nodes` map according to its hd and lvl.
        nodes[hd][lvl].push_back(frontNode->data);

        // If the left child exists, push it onto the queue with updated hd and lvl.
        // The left child's hd is (hd - 1) and its lvl is (lvl + 1).
        if (frontNode->left) {
            q.push(std::make_pair(frontNode->left, std::make_pair(hd - 1, lvl + 1)));
        }

        // If the right child exists, push it onto the queue with updated hd and lvl.
        // The right child's hd is (hd + 1) and its lvl is (lvl + 1).
        if (frontNode->right) {
            q.push(std::make_pair(frontNode->right, std::make_pair(hd + 1, lvl + 1)));
        }
    }

    // Traverse the `nodes` map to construct the final vertical order traversal.
    // The map is automatically sorted by keys, so it will go from the lowest hd to the highest.
    for (auto i : nodes) {
        // For each hd, traverse the levels (lvl).
        for (auto j : i.second) {
            // For each level, add all nodes at that level to the `ans` vector.
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    // Return the final list of nodes in vertical order.
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

    std::vector<int> result = verticalOrder(root);

    // Print the vertical order traversal result.
    std::cout << "Vertical Order Traversal: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}