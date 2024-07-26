#include <iostream>
#include <queue>

int main() 
{
    // Creating a queue of integers
    std::queue<int> myQueue;

    // Pushing elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);

    // Printing the size of the queue
    std::cout << "Size of the queue: " << myQueue.size() << std::endl;

    // Accessing the front and back elements of the queue
    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;

    // Popping elements from the queue
    myQueue.pop();

    // Printing the front element after popping
    std::cout << "Front element after popping: " << myQueue.front() << std::endl;

    return 0;
}


//FIFO -> First in, First out

//Example -> People standing in line. 1st person's work will done 1st and come out first.