//factorial example
#include <iostream>

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
}

int main()
{
    int n;
    std::cin >> n;

    int ans = factorial(n);

    std::cout<<ans;

    return 0;
}