#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

bool ispar(std::string x)
{
    std::stack<char> s;
    for (int i = 0; i < x.length(); i++) 
    {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
                s.push(x[i]);
            
        else if (x[i] == ')') 
        {
            if (s.empty() || s.top() != '(') 
                return false;
            s.pop();
            
        } 
        else if (x[i] == '}') 
        {
            if (s.empty() || s.top() != '{')
                return false;
                s.pop();
        } 
        else if (x[i] == ']') 
        {
            if (s.empty() || s.top() != '[')
                return false;
                s.pop();
        }
    }
    return s.empty(); 
}

int main()
{
    std::string str = "{([])}";
    
    bool ans = ispar(str);

    std::cout<<ans;


    return 0;
}

