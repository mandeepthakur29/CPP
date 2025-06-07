#include <iostream>

int main()
{
    int num = 10;
    int *p = &num;

    std::cout<<"Value is: "<<*p<<std::endl;

    int *q = p; //copying one pointer into another

    std::cout<<"Value is: "<<*q<<std::endl; //same output as *p
}