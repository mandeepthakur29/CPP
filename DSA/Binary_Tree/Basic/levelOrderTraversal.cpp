// Level order traversal, also known as breadth-first traversal, is a method of traversing a tree level 
// by level from the root to the leaves. In this traversal, nodes are visited level by level, starting 
// from the root and moving downwards to each subsequent level.

#include <iostream>
#include <queue>

class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    std::cout<<"Enter Data: ";
    int data;
    std::cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    std::cout<<"Enter data for inserting in left of: "<<data<<std::endl;
    root->left = buildTree(root->left);
    std::cout<<"Enter data for inserting in right of: "<<data<<std::endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    std::queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            std::cout<<std::endl;

            if(!q.empty()){
                q.push(NULL);   
            }
        }

        else{
            std::cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;

    root = buildTree(root);

    std::cout<<"Printing the level order traversal output: "<<std::endl;
    levelOrderTraversal(root);

    return 0;
}
//1 3 7  -1 -1 11 -1 -1 5 17 -1 -1 -1