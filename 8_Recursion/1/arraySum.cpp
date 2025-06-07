#include <iostream>

int arraySum(int arr[], int size){
    if(size == 0){
        return 0;
    }
    int sum = arr[0];
    sum = sum + arraySum(arr+1, size-1);
    return sum;
}

int main(){

    int arr[5] = {3,2,5,1,6}; 
    int size = 5; 

    int ans = arraySum(arr, size);
    std::cout<<ans<<std::endl;
   

    return 0;
}
