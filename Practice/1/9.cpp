#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++)
        {
            int j = i+1;
            if(nums[i] == nums[j])
            {
                return true;
            }
        }
        return false;
    }

int main()
{
    std::vector<int> nums1 = {1,2,3,4};
    
    bool ans = containsDuplicate(nums1);
    std::cout<<"ans: "<<ans;

    return 0;
}

