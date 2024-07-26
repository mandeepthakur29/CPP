#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<int> leaders(int a[], int n) 
{
    std::vector<int> ans;
        int max = a[n-1];
        ans.push_back(max);
        for(int i=n-2; i>=0; i--)
        {
            if(a[i]<max)
            {
                continue;
            }
            max=a[i];
            ans.push_back(max);
            
        }
        std::reverse(ans.begin(),ans.end());
        
        return ans;
}



int main()
{
    int arr[6] = {16,17,10,3,5,2};
    
    std::vector<int> ans = leaders(arr, 6);

    for(auto i : ans)
    {
        std::cout<< i<<" ";
    }


    return 0;
}

