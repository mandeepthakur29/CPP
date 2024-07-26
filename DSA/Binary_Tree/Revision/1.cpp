#include <iostream>
#include <queue>
#include <stack>

class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// node* buildTree(node* root)
// {
//     std::cout<<"Enter data: ";
//     int data;
//     std::cin>>data;

//     if(data == -1){
//         return NULL;
//     }

//     root = new node(data);

//     std::cout<<"Enter the left side data of "<<data;
//     root->left = buildTree(root->left);

//     std::cout<<"Enter the right side data of "<<data;
//     root->right = buildTree(root->right);

//     return root;
// }

void printingTree(node* root)
{
    std::queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            std::cout<<std::endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
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

void reverseLOT(node* root)
{
    std::queue<node*> q;
    std::stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        s.push(temp);
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    while(!s.empty()){
        node*temp = s.top();
        s.pop();
        std::cout<<temp->data<<" ";
    }
}

void createTreeFromLevelOrder(node* &root)
{
    std::queue<node*> q;
    std::cout<<"Enter data for root: ";
    int data;
    std::cin>>data;
    root = new node(data);
    q.push(root);


}

int main()
{
    node* root = NULL;

    createTreeFromLevelOrder(root);
    //root = buildTree(root);
    printingTree(root);
    reverseLOT(root);
}