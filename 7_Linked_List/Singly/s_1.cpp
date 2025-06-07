#include <iostream>

// Node class definition
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the linked list

    // Constructor to initialize a node with a given value
    Node(int value)
    {
        this->data = value; // Assign the given value to the data member
        this->next = NULL;  // Initialize the next pointer to NULL (no next node)
    }
};

int main()
{
    // Create a new node with data value 10
    Node *node1 = new Node(10);

    // Output the data and next pointer of the node
    std::cout << "Data is: " << node1->data << std::endl;
    std::cout << "Next is: " << node1->next << std::endl;

    return 0;
}
