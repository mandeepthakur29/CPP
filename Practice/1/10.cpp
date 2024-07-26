#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <climits>

bool isAnagram(std::string s, std::string t) 
{
    if(s.size() != t.size())
        {
            return false;
        }
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (int i = 0; i <= s.size(); i++) {
            if (s.substr(i, 1) != t.substr(i, 1)) {
                return false;
            }
        }
        return true;
}

int main()
{
    std::string s = "anagram";
    std::string t = "nagaram";
    
    bool ans = isAnagram(s, t);
    std::cout<<"ans: "<<ans;

    return 0;
}

