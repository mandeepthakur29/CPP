//Insertion at ending of Linked List

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
};

void print(Node* &head)
{
    // Create a temporary pointer to traverse the linked list
    Node* temp = head;

    // Traverse the linked list until reaching the end (NULL)
    while(temp != NULL)
    {
        // Print the data stored in the current node
        std::cout << temp->data << std::endl;
        
        // Move the temporary pointer to the next node in the list
        temp = temp->next;
    }
}

void insertAtLast(Node* &tail, int num)
{
    // Create a new node with the given data
    Node* temp = new Node(num);
    
    // Set the next pointer of the current tail node to point to the new node
    tail->next = temp;
    
    // Update the tail pointer to point to the new node, making it the new tail
    tail = temp;
}


int main()
{
    // Create a new node with data 10 and store its address in node1
    Node *node1 = new Node(11);
    
    // Print the data and next pointer of node1
    std::cout << "Data is: " << node1->data << std::endl;
    std::cout << "Next is: " << node1->next << std::endl;

    // Set the head pointer to point to node1
    Node* head = node1;
    Node* tail = node1;

    // Print the elements of the linked list starting from the head
    print(head);

    // Insert a new node with data 12 at the tail of the linked list
    insertAtLast(tail, 12);
    insertAtLast(tail, 13);
    
    // Print a message indicating that the insertion is complete
    std::cout<<"Insertion Complete."<<std::endl;
    
    // Print the elements of the linked list after insertion
    print(head);

    return 0;
}

