#include <iostream>

void numOut(int n)
{
    if(n == 0)
    {
        return ;
    }
    numOut(n-1);

    std::cout<<n;
}

int main()
{
    int n;
    std::cin >> n;

    numOut(n);

    return 0;
}