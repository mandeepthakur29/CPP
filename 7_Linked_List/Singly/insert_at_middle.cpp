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

void insertAtHead(Node* &head, int data) 
{
    // Create a new node with the provided data
    Node *temp = new Node(data);

    // Set the next pointer of the new node to point to the current head of the list>
    //it ensures that the new node temp is linked to the rest of the list by pointing to the head node.
    temp->next = head;//here, temp pointed to head, to become a member of LL. 

    // Update the head pointer to point to the newly created node
    //it makes the newly inserted node i.e. temp, the new head of the linked list.
    head = temp;//here, temp become the head of LL
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtLast(Node* &tail, int num)
{
    Node* temp = new Node(num);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &tail, Node* &head, int position, int num)
{
    // insert at head
    if(position == 1)
    {
        insertAtHead(head, num); // Call the insertAtHead function
        return; // Exit the function
    }

    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    
    // Initialize a counter to track the current position while traversing
    int count = 1;
    
    // Traverse the list until the desired position minus one
    // This loop stops at the node before the intended insertion position
    while(count != position - 1)
    {
        // Move to the next node
        temp = temp->next;
        
        // Increment the counter
        count++;
    }

    //insert at last/tail
    if(temp -> next == NULL)
    {
        insertAtLast(tail, num);
        return;
    }

    // Create a new node to insert with the given data
    Node* toInsert = new Node(num);
    
    // Link the new node to the rest of the list
    // First, set its next pointer to the next node of the current position
    toInsert->next = temp->next;
    
    // Then, update the next pointer of the current position node to point to the new node
    temp->next = toInsert;
}


int main()
{
    Node *node1 = new Node(11);
    
    std::cout << "Data is: " << node1->data << std::endl;
    std::cout << "Next is: " << node1->next << std::endl;

    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtLast(tail, 12);
    insertAtLast(tail, 14);
    
    std::cout<<"Insertion Complete."<<std::endl;
    print(head);

    insertAtMiddle(tail, head, 4, 13);
    print(head);

    return 0;
}

