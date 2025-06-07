#include <iostream>

// Function to check if an array is sorted in ascending order recursively
bool isSorted(int arr[], int size){

    // Base case: if array has 0 or 1 element, it's considered sorted
    if(size == 0 || size == 1){
        return true;
    }
    // Checking if the first element is greater than the second element
    if(arr[0] > arr[1]){
        // If so, the array is not sorted
        return false;
    }
    else{
        // Recursively call the function with the remaining part of the array
        // excluding the first element, and reduce the size by 1
        bool remainingPart = isSorted(arr+1, size-1);
        return remainingPart;
    }

}

int main(){

    int arr[5] = {1,2,3,4,5}; 
    int size = 5; 

    bool ans = isSorted(arr, size);

    // Printing the result
    std::cout << std::boolalpha << ans << std::endl;

    return 0;
}

// std::boolalpha is a manipulator in C++ that can be used with output streams like std::cout to modify the 
// formatting of boolean values. When std::boolalpha is set, boolean values are printed as true or false 
// instead of 1 or 0.
