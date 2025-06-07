#include <iostream>
#include <algorithm>

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

std::pair<int,int> diameterFast(Node* root)
{
    if(root == NULL){
        std::pair<int,int>p = std::make_pair(0,0);
        return p;
    }

    std::pair<int,int> left = diameterFast(root->left);
    std::pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    std::pair<int,int> ans;
    
    ans.first = std::max(op1, std::max(op2, op3));
    ans.second = std::max(left.second, right.second)+1;

    return ans;
}

int diameter(Node* root){
    std::pair<int,int> ans;
    ans = diameterFast(root);
    return ans.first;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout<<"Diameter of tree: "<<diameter(root);
}