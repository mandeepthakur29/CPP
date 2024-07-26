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
    std::cout<<"Enter data: ";
    int data;
    std::cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    std::cout<<"Enter data to the left side of "<<data<<": ";
    root->left = buildTree(root->left);
    std::cout<<"Enter data to the right side of "<<data<<": ";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root)
{
   std::queue<node*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty())
   {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            std::cout<<std::endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
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

    levelOrderTraversal(root);

    return 0;
}
