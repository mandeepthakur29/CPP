#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <sstream>  // For istringstream
#include <vector>   // For vector

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    
    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            return make_pair(0,0);
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(Node* root) {
    
        return diameterFast(root).first;
        
    }
};

int main() {
    // Manually creating the binary tree
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution ob;
    cout << "Diameter of the tree: " << ob.diameter(root) << endl;
    
    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
