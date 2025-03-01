#include <iostream>
#include <map>
#include <queue>

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to create a mapping of each node to its parent and find the target node
Node* createParentMapping(Node* root, int target, std::map<Node*, Node*> &nodeToParent) {
    Node* res = NULL;  // Initialize the result node (target node) to NULL

    std::queue<Node*> q;  // Queue for level order traversal
    q.push(root);  // Start the traversal from the root node
    nodeToParent[root] = NULL;  // Root node has no parent, so map it to NULL

    while (!q.empty()) {
        Node* front = q.front();  // Get the front node from the queue
        q.pop();  // Remove the front node from the queue

        // Check if this node is the target node
        if (front->data == target)
            res = front;  // If yes, store it in the result

        // If the node has a left child, map it to its parent and add it to the queue
        if (front->left) {
            nodeToParent[front->left] = front;  // Map left child to its parent
            q.push(front->left);  // Add left child to the queue for further processing
        }

        // If the node has a right child, map it to its parent and add it to the queue
        if (front->right) {
            nodeToParent[front->right] = front;  // Map right child to its parent
            q.push(front->right);  // Add right child to the queue for further processing
        }
    }
    return res;  // Return the target node
}

// Function to burn the tree starting from the target node and calculate the time taken
int burnTree(Node* targetNode, std::map<Node*, Node*> &nodeToParent) {
    std::map<Node*, bool> visited;  // Map to track visited nodes to avoid processing them again
    std::queue<Node*> q;  // Queue for processing nodes in BFS manner (level by level)

    q.push(targetNode);  // Start burning from the target node
    visited[targetNode] = true;  // Mark the target node as visited

    int ans = 0;  // Initialize the time taken to burn the tree

    while (!q.empty()) {
        bool flag = 0;  // Flag to check if any node at the current level spreads the fire
        int size = q.size();  // Get the number of nodes at the current level

        // Process all nodes at the current level
        for (int i = 0; i < size; i++) 
        {
            Node* front = q.front();  // Get the front node in the queue
            q.pop();  // Remove it from the queue

            // Check the left child: if it exists and hasn't been visited, it will catch fire
            if (front->left && !visited[front->left]) {
                flag = 1;  // Set flag to 1 as fire spreads to the left child
                q.push(front->left);  // Add the left child to the queue for further processing
                visited[front->left] = 1;  // Mark the left child as visited
            }

            // Check the right child: if it exists and hasn't been visited, it will catch fire
            if (front->right && !visited[front->right]) {
                flag = 1;  // Set flag to 1 as fire spreads to the right child
                q.push(front->right);  // Add the right child to the queue for further processing
                visited[front->right] = 1;  // Mark the right child as visited
            }

            // Check the parent: if it exists and hasn't been visited, it will catch fire
            if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;  // Set flag to 1 as fire spreads to the parent
                q.push(nodeToParent[front]);  // Add the parent to the queue for further processing
                visited[nodeToParent[front]] = 1;  // Mark the parent as visited
            }
        }

        // If fire has spread to any node at this level, increment the time taken
        if (flag == 1)
            ans++;
    }

    return ans;  // Return the total time taken to burn the entire tree
}

// Function to calculate the minimum time to burn the entire tree from the target node
int minTime(Node* root, int target) {
    std::map<Node*, Node*> nodeToParent;  // Map to store parent-child relationships
    Node* targetNode = createParentMapping(root, target, nodeToParent);  // Find target node and create parent mappings
    int ans = burnTree(targetNode, nodeToParent);  // Calculate time to burn the tree starting from the target node
    return ans;
}

// Main function to test the code
int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right->right = new Node(6);

    int target = 2;
    std::cout << "Minimum time to burn the tree: " << minTime(root, target) << std::endl;

    return 0;
}
