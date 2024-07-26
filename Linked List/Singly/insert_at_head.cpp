//Insertion at begginning of Linked List

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

// Function to insert a new node at the head of the linked list
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


#include <iostream>

int main()
{
    // Create a new node with data 10 and store its address in node1
    Node *node1 = new Node(10);
    
    // Print the data and next pointer of node1
    std::cout << "Data is: " << node1->data << std::endl;
    std::cout << "Next is: " << node1->next << std::endl;

    // Set the head pointer to point to node1
    Node* head = node1;

    // Print the elements of the linked list starting from the head
    print(head);

    // Insert a new node with data 12 at the head of the linked list
    insertAtHead(head, 12);
    
    // Print a message indicating that the insertion is complete
    std::cout<<"Insertion Complete."<<std::endl;
    
    // Print the elements of the linked list after insertion
    print(head);

    return 0;
}


//NOTE:1
// In the function parameter Node* &head, Node* declares head as a pointer to a Node. The & symbol indicates 
// that head is passed by reference, meaning that changes to head inside the function will affect the original 
// pointer passed to the function.

//NOTE:2

// In the first line, temp->next = head;, we're linking the new node (temp) to the rest of the linked list by making 
// its next pointer point to the current head of the list.
// In the second line, head = temp;, we're updating the head pointer to point to the newly created node (temp). 
// This effectively makes the new node the new head of the linked list, as it's now the first node that will be 
// traversed when accessing the list from the beginning.



/*
Another example
void push(Node** head_ref, int new_data)
{

	allocate node
	Node* new_node = new Node();

	put in the data
	new_node->data = new_data;

	Make next of new node as head
	new_node->next = (*head_ref); here, new node pointed to head, to become a member of LL. 

	Move the head to point to the new node
	(*head_ref) = new_node; here, new node become the head of LL
}
*/
