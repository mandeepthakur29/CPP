#include <iostream>

int main()
{
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    std::cout<< arr <<std::endl; //output is address in "int" data type
    std::cout<< ch <<std::endl; //output is whole value in "char" data type due to "null character" at the end of string.

    return 0;
}