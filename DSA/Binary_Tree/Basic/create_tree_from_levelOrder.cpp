#include <iostream>
#include <queue>

class node 
{
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

void buildFromLevelOrder(node* &root) //building tree
{
    std::queue<node*> q;
    std::cout<<"Enter data for root: "<<std::endl;
    int data;
    std::cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        std::cout<<"Enter left node for "<<temp->data<<std::endl;
        int leftData;
        std::cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        std::cout<<"Enter right node for "<<temp->data<<std::endl;
        int rightData;
        std::cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){ //*showing tree
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

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    return 0;
}
