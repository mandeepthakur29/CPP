#include <iostream>
#include <algorithm> // For std::max and std::abs

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(NULL), right(NULL) {}
};

std::pair<bool,int> isSumTreeFast(Node* root)
{
    if(root == NULL){
        return std::make_pair(true, 0);
    }

    if(root->left == NULL && root->right == NULL){
        return std::make_pair(true, root->data);
    }

    std::pair<bool,int> leftAns = isSumTreeFast(root->left);
    std::pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root->data == leftAns.second + rightAns.second;

    std::pair<bool,int> ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = 2* root->data;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isSumTree(root)) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
