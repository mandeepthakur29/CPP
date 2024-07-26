#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>

int removeDuplicates(std::vector<int>& nums) 
{
   if(nums.size() == 0)
        {
            return 0;
        }
        int k = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
}

int main()
{
    std::vector<int> nums1 = {1,1,2,3};
    
    int ans = removeDuplicates(nums1);
    std::cout<<"ans:";
    std::cout<<ans;

    return 0;
}

