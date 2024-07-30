#include <iostream>
#include <queue>
#include <stack>

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    std::cout << "Enter Data: ";
    int data;
    std::cin >> data;

    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    std::cout << "Enter data for inserting in left of: " << data << std::endl;
    root->left = buildTree(root->left);
    std::cout << "Enter data for inserting in right of: " << data << std::endl;
    root->right = buildTree(root->right);

    return root;
}

void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    std::queue<node*> q;
    std::stack<node*> s;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        // Note that right child is enqueued before left child
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Print nodes in reverse order
    while (!s.empty()) {
        node* temp = s.top();
        std::cout << temp->data << " ";
        s.pop();
    }
}

int main() {
    node* root = NULL;

    root = buildTree(root);

    std::cout << "Printing the reverse level order traversal output: " << std::endl;
    reverseLevelOrderTraversal(root);

    return 0;
}

//LINE-51:- Enqueue the right child before the left child to ensure that left children are processed before right 
            //children when popping from the stack.