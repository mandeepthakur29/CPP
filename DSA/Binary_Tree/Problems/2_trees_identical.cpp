#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool areIdentical(Node* root1, Node* root2) 
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    } 
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = areIdentical(root1->left, root2->left);
    bool right = areIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    // Create first tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Create second tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if (areIdentical(root1, root2)) {
        std::cout << "The trees are identical." << std::endl;
    } else {
        std::cout << "The trees are not identical." << std::endl;
    }

    // Clean up memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;
    
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
