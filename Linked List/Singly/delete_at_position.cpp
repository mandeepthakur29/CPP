#include <iostream>

class Node
{
public:
    int data;   
    Node *next; 

    Node(int value)
    {
        this->data = value; 
        this->next = NULL; 
    }

    ~Node()
{
    // Get the value stored in the current node
    int value = this->data;

    // Check if the current node has a next node
    if (this->next != NULL)
    {
        // Recursively delete the next node and its subsequent nodes
        delete next;

        // Set the next pointer of the current node to NULL to avoid dangling pointers
        this->next = NULL;
    }

    // Output a message indicating that memory is being freed for the current node
    std::cout << "Memory is free for node with data: " << value << std::endl;
}

};

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void insertAtLast(Node* &tail, int num)
{
    Node* temp = new Node(num);
    tail->next = temp;
    tail = temp;
}

// void deleteNode(Node* &head, int value)
// {

// }

void deleteNode(Node* &head, int position)
{
    // Deleting the first or start node
    if (position == 1)
    {
        // Store a temporary pointer to the current head
        Node* temp = head;
        
        // Move the head pointer to the next node
        head = head->next;
        
        // Set the next pointer of the temporary node to NULL
        temp->next = NULL;
        
        // Deallocate memory for the temporary node
        delete temp;
    }
    else
    {
        // Deleting any middle or last node
        Node* curr = head;  // Pointer to traverse the list
        Node* prev = NULL;  // Pointer to keep track of the previous node

        // Traverse the list until reaching the desired position
        int cnt = 1;
        while (cnt <= position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        // Adjust the pointers to bypass the node to be deleted
        prev->next = curr->next;
        
        // Set the next pointer of the node to be deleted to NULL
        curr->next = NULL;
        
        // Deallocate memory for the node to be deleted
        delete curr;
    }
}


int main()
{
    Node *node1 = new Node(11);

    Node* head = node1;
    Node* tail = node1;

    insertAtLast(tail, 12);
    insertAtLast(tail, 13);
    insertAtLast(tail, 14);
    insertAtLast(tail, 15);
    print(head);

    deleteNode(head, 2);
    print(head);

    return 0;
}

