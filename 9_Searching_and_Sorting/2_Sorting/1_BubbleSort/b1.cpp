#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

void BubbleSort(std::vector<int>& nums) 
{
    int n = nums.size();
    bool swap = false;
    for(int i=0; i<=n-1; i++)
    {
        for(int j=1; j<n-i; j++)
        {
            if(nums[j-1] > nums[j])
            {
                std::swap(nums[j-1], nums[j]);
                swap = true;
            }
        }
        if(swap == false)
            break;
    }

    for(int k =0; k<=n-1; k++)
    {
        std::cout<<nums[k]<<" ";
    }
}

int main()
{
    std::vector<int> nums = {3,0,1,18,9,14};
    
    BubbleSort(nums);

    return 0;
}

