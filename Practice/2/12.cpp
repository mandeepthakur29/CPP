#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    std::unordered_set<int> s1(nums1.begin(), nums1.end());
    std::unordered_set<int> s2(nums2.begin(), nums2.end());
    std::vector<int>ans;

        for (auto i : s1) {
            for (auto j : s2) {
                if (i == j) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
}

int main()
{
    std::vector<int> nums = {1,2,2,1};
    std::vector<int> nums1 = {2,2};
    
    std::vector<int>ans = intersection(nums,nums1);
    
    for(int i=0; i<=ans.size(); i++)
    {
        std::cout<<ans[i]<<" ";
    }

    return 0;
}

