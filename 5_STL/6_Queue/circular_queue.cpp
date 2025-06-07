// A circular queue is a linear data structure that follows the FIFO (First In First Out) principle, but unlike a 
// regular queue, the last position is connected back to the first position to make a circle. This makes efficient 
// use of space by reusing vacated slots.

#include <iostream>
#define SIZE 5  

class CircularQueue {
private:
    int items[SIZE];  
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;  // Queue is initially empty, so set front to -1
        rear = -1;   // Queue is initially empty, so set rear to -1
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {  // Check if the queue is full
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (front == -1) {  // If the queue is initially empty, set front to 0
            front = 0;
        }
        rear = (rear + 1) % SIZE;  // Increment rear in a circular manner
        items[rear] = value;  // Add the new element
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {  // Check if the queue is empty
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        if (front == rear) {  // If the queue has only one element
            front = -1;  // Reset front and rear to -1
            rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Increment front in a circular manner
        }
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
        int i = front;
        while (true) {
            std::cout << items[i] << " ";
            if (i == rear) break;  // Stop when we reach the rear element
            i = (i + 1) % SIZE;  // Move to the next element in a circular manner
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);  // Add 10 to the queue
    q.enqueue(20);  // Add 20 to the queue
    q.enqueue(30);  // Add 30 to the queue
    q.enqueue(40);  // Add 40 to the queue
    q.enqueue(50);  // Add 50 to the queue

    q.display();  // Display the queue elements

    q.dequeue();  // Remove an element from the queue
    q.display();  // Display the queue elements

    q.enqueue(60);  // Add 60 to the queue
    q.display();  // Display the queue elements

    std::cout << "Front element is: " << q.getFront() << std::endl;  // Display the front element

    return 0;
}
