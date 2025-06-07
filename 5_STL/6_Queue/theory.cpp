1.) Key Components: Front and Rear:

=> Front is the index of the first element in the queue.
=> Rear is the index of the last element in the queue.
=> Array: An array of fixed size is used to implement the queue.

2.) Key Operations:

    a.) Initialization: front and rear are initialized to -1 to indicate the queue is empty.
    b.) isFull(): The queue is full if (front == 0 && rear == SIZE - 1) or front == rear + 1.
    c.) isEmpty(): The queue is empty if front == -1.
    d.) enqueue(int value):
        Check if the queue is full. If yes, print "Queue is full".
        If the queue is empty (i.e., front == -1), set front to 0.
        Increment rear in a circular manner using (rear + 1) % SIZE.
        Add the new element to the position indicated by rear.
    e.) dequeue():
        Check if the queue is empty. If yes, print "Queue is empty".
        If front equals rear, it means the queue has only one element. Set both front and rear to -1 (reset the queue).
        Otherwise, increment front in a circular manner using (front + 1) % SIZE.
    f.) getFront(): Return the element at the front index if the queue is not empty.
    g.) display(): Print all the elements from front to rear in a circular manner.
