#include <iostream>
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

void inorderTraversal(node* root) {
    std::stack<node*> stack;
    node* current = root;

    while (current != NULL || !stack.empty()) {
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        std::cout << current->data << " ";

        current = current->right;
    }
}

void preorderTraversal(node* root) {
    if (root == NULL) return;

    std::stack<node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        node* current = stack.top();
        stack.pop();
        std::cout << current->data << " ";

        if (current->right) {
            stack.push(current->right);
        }
        if (current->left) {
            stack.push(current->left);
        }
    }
}

void postorderTraversal(node* root) {
    if (root == NULL) return;

    std::stack<node*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        node* current = stack1.top();
        stack1.pop();
        stack2.push(current);

        if (current->left) {
            stack1.push(current->left);
        }
        if (current->right) {
            stack1.push(current->right);
        }
    }

    while (!stack2.empty()) {
        node* current = stack2.top();
        stack2.pop();
        std::cout << current->data << " ";
    }
}

int main() {
    node* root = NULL;

    // Building the tree
    root = buildTree(root);

    // Traversals
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
