#include <iostream>

int main()
{
    int num = 10;
    int a = num;
    a++;

    std::cout<<"num is: "<< num <<std::endl; 
    //here, changes to 'a' does not effect 'num'. as, value was copied there, but...


    int *ptr = &num;
    std::cout<<"Before: "<<num<<std::endl;
    (*ptr)++; //dereferencing
    std::cout<<"After: "<<num<<std::endl;
}