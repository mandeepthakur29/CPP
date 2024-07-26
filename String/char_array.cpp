#include <iostream>

int getLength(char arr[])
{
    int count = 0;
    for(int i=0; arr[i] !='\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char arr[10];

    std::cin>>arr;

    std::cout<<"Char is: "<< arr<<std::endl;

    std::cout<< getLength(arr);
}