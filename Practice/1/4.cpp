#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    nums1.erase(nums1.end() - n, nums1.end());
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());

    for(auto i: nums1)
    {
        std::cout<<i;
    }
}

int main()
{
    std::vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    std::vector<int> nums2 = {1,2,2};
    
    merge(nums1, 6, nums2, 3);

    return 0;
}

