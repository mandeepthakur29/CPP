#include <iostream>

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

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(node* root) {
    if (root == NULL) return;
    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
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
