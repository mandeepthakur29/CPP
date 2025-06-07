#include <iostream>
#define SIZE 100  // Define the maximum size of the queue

// Queue class
class Queue {
private:
    int items[SIZE];  // Array to store queue elements
    int front;        // Index of the front element
    int rear;         // Index of the rear element

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;  // Queue is initially empty, so set front to -1
        rear = -1;   // Queue is initially empty, so set rear to -1
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == SIZE - 1;  // Queue is full if rear is at the last index
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;  // Queue is empty if front is -1 or front is greater than rear
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {  // Check if the queue is full
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (front == -1) front = 0;  // If the queue is initially empty, set front to 0
        items[++rear] = value;  // Increment rear and add the new element
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {  // Check if the queue is empty
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        front++;  // Increment front to remove the front element
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {  // Check if the queue is empty
            std::cout << "Queue is empty" << std::endl;
            return -1;  // Return -1 if the queue is empty
        }
        return items[front];  // Return the front element
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {  // Check if the queue is empty
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        for (int i = front; i <= rear; i++) {  // Iterate through the queue elements
            std::cout << items[i] << " ";  // Print each element
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);  // Add 10 to the queue
    q.enqueue(20);  // Add 20 to the queue
    q.enqueue(30);  // Add 30 to the queue

    q.display();  // Display the queue elements

    q.dequeue();  // Remove an element from the queue
    q.display();  // Display the queue elements

    std::cout << "Front element is: " << q.getFront() << std::endl;  // Display the front element

    return 0;
}
