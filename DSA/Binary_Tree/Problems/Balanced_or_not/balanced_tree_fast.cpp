//Tree is balanced or not (Brute Force Approach)
#include <iostream>
#include <algorithm> // For std::max and std::abs

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Function to check if a tree is balanced
std::pair<bool,int> isBalancedFast(Node* root)
{
    if(root == NULL)
    {
        return std::make_pair(true, 0);
    }

    std::pair<bool,int> left = isBalancedFast(root->left);
    std::pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    std::pair<bool,int> ans;
    ans.second = std::max(left.second, right.second) +1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

bool isBalanced(Node* root)
{
    return isBalancedFast(root).first;
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root)) {
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
