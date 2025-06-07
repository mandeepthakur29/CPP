#include <iostream>
#include <algorithm>

class heap {
    public:
        int arr[100];  
        int size;     

    heap() {
        arr[0] = -1;  
        size = 0; 
    }

    void insert(int val) {
        size = size + 1;
        int index = size;   
        arr[index] = val;  

        while(index > 1) { 
        
            int parent = index / 2; 

            if(arr[parent] < arr[index]) {
                std::swap(arr[parent], arr[index]);
                index = parent; 
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            std::cout << arr[i] << " "; 
        }
        std::cout << std::endl; 
    }

    void deleteFromHeap() 
    {
    // Check if the heap is empty
    if (size == 0) {
        std::cout << "Heap is Empty." << std::endl;
        return;
    }

    // Replace the root of the heap (arr[1]) with the last element
    arr[1] = arr[size];
    
    // Decrease the size of the heap, effectively removing the last element
    size--;

    // Initialize the index of the current node, starting from the root
    int i = 1;
    
    // Continue heapifying until the node is in its correct position
    while (i < size)
    {
        // Compute indices of the left and right children  
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;

        // Check if the left child exists and is greater than the current node
        if (leftIndex <= size && arr[i] < arr[leftIndex])
        {
            // Swap the current node with the left child
            std::swap(arr[leftIndex], arr[i]);
            // Move to the left child
            i = leftIndex;
        }
        // Check if the right child exists and is greater than the current node
        else if (rightIndex <= size && arr[i] < arr[rightIndex]) {
            // Swap the current node with the right child
            std::swap(arr[rightIndex], arr[i]);
            // Move to the right child
            i = rightIndex;
        }
        else {
            // If neither child is greater, the heap property is restored
            return;
        }
    }
}   

};

int main() {
    heap h; 

    
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print(); 

    h.deleteFromHeap();

    return 0;
}
