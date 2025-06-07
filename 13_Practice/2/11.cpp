#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

int missingNumber(std::vector<int>& nums) 
{
    std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();
}

int main()
{
    std::vector<int> nums = {3,0,1}; //0,1,2,3,4,5,6,7,9
    
    int ans = missingNumber(nums);
    std::cout<<"ans: "<<ans;

    return 0;
}

