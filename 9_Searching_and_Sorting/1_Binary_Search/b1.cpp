#include <iostream>

int binarySearch(int *arr, int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while(end >= start)
    {
        if(key == arr[mid])
        {
            return mid;
        }
        else if(key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (mid - start)/2;
    }
    return -1;
}

int main()
{
    int array[10] = {0,5,8,27,95,123,125,220,500,700};

    int ans = binarySearch(array, 10, 5);

    std::cout<<ans;


    return 0;
}

// In binary search, the calculation of the middle index (start + end) / 2 can lead to integer overflow, especially when dealing 
// with large values of start and end. To prevent overflow and ensure correct calculation of the middle index, the expression is 
// modified to start + (end - start) / 2.