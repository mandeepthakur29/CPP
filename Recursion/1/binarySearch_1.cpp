#include <iostream>

bool binarySearch(int arr[], int start, int end, int key){

    if(start>end){
        return false;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] > key){
        return binarySearch(arr, start, mid-1, key);
    }
    if(arr[mid] < key){
        return binarySearch(arr, mid+1, end, key);
    }

    return false;
}

int main(){

    int arr[6] = {2,5,7,9,10,13};
    int size = 6;
    int key = 16;

    bool ans = binarySearch(arr, 0, 6, key);
    std::cout<<std::boolalpha<<ans<<std::endl;

}