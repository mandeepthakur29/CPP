#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) 
{
    int n = arr.size();
    for(int i=1; i<=n-1; i++)
    {
        int temp = arr[i], j;
        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break; //break out of inner loop
            }
        }
        arr[j+1] = temp;
    }
}

int main() {
    std::vector<int> arr = {11, 12, 13, 5, 6};

    insertionSort(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
