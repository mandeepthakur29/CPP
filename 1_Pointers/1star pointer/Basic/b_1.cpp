#include <iostream>

int main()
{
    int a = 10;
    int *ptr = &a;

    std::cout<<"Value of a is: "<<a<<std::endl;

    std::cout<<"Address of a is: "<<&a<<std::endl;

    std::cout<<"Address of a is: "<<ptr<<std::endl;

    std::cout<<"Value of a is: "<<*ptr<<std::endl;
}