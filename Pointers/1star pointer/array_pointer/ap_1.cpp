#include <iostream>

int main()
{
    int arr[5] = {10,20,30,40,50};

    std::cout<<"Address of 1st memory block is: "<< arr <<std::endl;
    std::cout<<"Also Address of 1st memory block is:"<< &arr[0]<<std::endl;
    //Both are same thing

    std::cout<<"Also:"<< *arr<<std::endl; //print value at [0] index. -> Dereference
    std::cout<<"Also2:"<< *arr + 1 <<std::endl; //this is [0] index value + 1.
    std::cout<<"Also2:"<< *(arr + 1) <<std::endl; //"arr + 1" means [0]'s index + 1 i.e. [1]'s 
                                                  //address and then by adding *, it prints [2] index's value
    
    
}