#include <iostream>

int main()
{
    int *num;
    num = new int;
    //or we can write "int *num = new int;"
    
    *num = 10;
    std::cout<<*num;

    return 0;
}