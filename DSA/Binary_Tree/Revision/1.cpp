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

int height(Node* root){
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return std::max(left, right)+1;
}

std::pair<int,int> diameterFast(Node* root)
{
    if(root == NULL){
        std::pair<int,int>p = std::make_pair(0,0);
        return p;
    }

    
}

int diameterUtil(Node* root){
    if(root == NULL)
        return 0;

    int op1 = diameterUtil(root->left);
    int op2 = diameterUtil(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int ans = std::max(op1, std::max(op2, op3));
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout<<"Diameter of tree: "<<diameterUtil(root);
}