#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

void selectionSort(std::vector<int> &arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    std::vector<int> nums1 = {1,7,2,4,0,3};
    
    selectionSort(nums1, 6);
    //std::cout<<"ans: "<<ans;

    return 0;
}