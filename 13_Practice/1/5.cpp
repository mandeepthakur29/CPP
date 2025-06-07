#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

int removeElement(std::vector<int>& nums, int val) {

        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        nums.shrink_to_fit();
        return nums.size();
    }

int main()
{
    std::vector<int> nums1 = {0,1,2,2,3,0,4,2};
    
    int ans = removeElement(nums1, 2);
    std::cout<<ans;

    return 0;
}

