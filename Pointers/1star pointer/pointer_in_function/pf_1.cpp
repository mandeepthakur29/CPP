// how varible reacts while sending them to functions using pointer

#include <iostream>

void update(int *p) //catching address "*p"
{
    *p = *p + 1; 
}

int main()
{
    int value = 5;
    int *p = &value;

    std::cout<<"Before: "<< *p <<std::endl; //printing value that is linked with 'p' address
    update(p); //sending address 
    std::cout<<"After: "<< *p <<std::endl; //printing value that is linked with 'p' address
}