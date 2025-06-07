// how arrays react while sending them to functions using pointer

#include <iostream>

int getSum(int *arr, int size) //can also write "int getSum(int arr[], int size)". both are same.
{
    int temp;
    for(int i=0; i<size; i++)
    {
        temp += arr[i];
    }
    return temp;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int *p = arr;

    std::cout<< getSum(arr, 5)<<std::endl;
}