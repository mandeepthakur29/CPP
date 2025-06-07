//power example

#include <iostream>

int powerFun(int power, int number)
{
    if(power == 0)
    {
        return 1;
    }

    int smallerProblem = powerFun(power-1, number);
    int biggerProblem = smallerProblem * number;

    return biggerProblem;

    //return number * powerFun(power-1, number); we can also just write this line

    //when "return biggerProblem;" is called, its not returning to main(), it will return to main, when the number 
    //of times powerFun() will return something to it.

    //lets say, powerFun() was called 5 times, so "return biggerProblem;" will return number to powerFun() 5 times, 
    //that will eventually get stored in smallerProblem, and then at last it will return to main().
}


int main()
{
    int power = 5, number = 2;

    int ans = powerFun(power, number);

    std::cout<<ans;

    return 0;
}