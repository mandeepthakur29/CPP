#include <iostream>
#include <queue>

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void levelOrderTraversal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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

// Function to insert a new value into the BST
Node* insertIntoBST(Node* root, int d)
{
    // Base case: If the current node (root) is NULL, we insert the new node here
    if(root == NULL){
        root = new Node(d);  // Create a new node with the given value 'd'
        return root;         // Return the new node as the root of this subtree
    }

    // If the value to be inserted is greater than the current node's value
    if(d > root->data)
    {
        // Recur to insert the value in the right subtree
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // Otherwise, recur to insert the value in the left subtree
        root->left = insertIntoBST(root->left, d);
    }

    // Return the root of the subtree after insertion
    return root;  // (Missing in original code but necessary to maintain the correct tree structure)
}

// Function to take input from the user and insert values into the BST
void takeInput(Node* &root)
{
    int data;
    std::cin >> data;  

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        std::cin >> data;
    }
}

int main() 
{
    Node* root = NULL;  

    std::cout << "Enter data to create BST: " << std::endl;
    takeInput(root);

    std::cout<<"Printing level order tarversal: "<<std::endl;
    levelOrderTraversal(root);

    return 0;
}
