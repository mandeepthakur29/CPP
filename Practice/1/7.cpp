#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

int maxProfit(std::vector<int>& prices) 
{
   if (prices.empty()) 
    {
        return 0;
    }
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i=0; i<prices.size(); i++)
    {
        if(minPrice > prices[i])
        {
            minPrice = prices[i];
        }
        else if(prices[i] - minPrice > maxProfit)
        {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int main()
{
    std::vector<int> nums1 = {7,1,5,3,6,4};
    
    int ans = maxProfit(nums1);
    std::cout<<"ans:";
    std::cout<<ans;

    return 0;
}

