#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

int searchInsert(std::vector<int>& nums, int target) 
{
    int end = nums.size()-1;
    int start = 0;
    int mid = start + (end - start)/2;

    while(end >= start)
    {
        if(target == nums[mid])
        {
            return mid;
        }
        else if(target > nums[mid])
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main()
{
    std::vector<int> nums1 = {1,3,5,6};
    
    int ans = searchInsert(nums1, 2);
    std::cout<<"ans: "<<ans;

    return 0;
}

