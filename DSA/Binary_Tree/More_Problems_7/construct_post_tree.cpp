#include <iostream>
#include <map>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void createMapping(int in[], std::map<int,int> &nodeToIndex, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, std::map<int,int> &nodeToIndex) 
{
    //base case
    if (index >= n || inorderStart > inorderEnd)
        return NULL;

    //create a root node for element
    int element = pre[index++];
    Node* root = new Node(element);

    //find element's index in inorder(it is map)
    int position = nodeToIndex[element];

    //recursive calls
    root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int pre[], int n) 
{
    int preOrderIndex = 0;
    std::map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, n); //create nodes to index map

    return solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
}

void printPostOrder(Node* root) 
{
    if (root == NULL)
        return;

    printPostOrder(root->left);  
    printPostOrder(root->right); 
    std::cout << root->data << " ";
}

int main() {
    // Example input
    int in[] = {1,6,8,7};     // Inorder traversal
    int pre[] = {1,6,7,8};    // Preorder traversal
    int n = sizeof(in)/sizeof(in[0]);

    // Build the tree from inorder and preorder arrays
    Node* root = buildTree(in, pre, n);

    // Print the postorder traversal of the constructed tree
    std::cout << "Postorder traversal of the constructed tree: ";
    printPostOrder(root);
    std::cout << std::endl;

    return 0;
}
