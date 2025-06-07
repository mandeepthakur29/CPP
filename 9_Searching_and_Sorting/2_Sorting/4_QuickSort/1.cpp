#include <iostream>

int partitioning(int arr[], int start, int end){

    int pivot = arr[start], cnt = 0;

    for(int i=start+1; i<=end; i++){
        if(arr[i] < pivot)
            cnt++;
    }
    int pivotIndex = start + cnt;
    std::swap(arr[start], arr[pivotIndex]);

    int i = start, j = end-1;

    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(int arr[], int start, int end){

    if(start<end)
    {
        int p = partitioning(arr, start, end);

        quickSort(arr, start, p-1);
        quickSort(arr, start, p+1);
    }

    for(int i=0; i<=end; i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[10] = {2,5,7,1,3,8,4,9,6,10};
    int size = sizeof(arr);

    quickSort(arr, 0, 10);
    return 0;
}