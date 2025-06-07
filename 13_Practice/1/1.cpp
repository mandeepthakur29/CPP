#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

int reverse(int x) {
        int ans = 0;
        while(x != 0)
        {
            if(ans > INT_MAX || ans < INT_MIN)
            {
                return 0;
            }
            int digit = x % 10;
            ans = ans * 10 + digit;
            x = x / 10;
        }
        return ans;
    }


int main()
{
    int n = 123;
    std::cout<<n%10;

    int ans = reverse(n);

    std::cout<<ans;

    return 0;
}
