#include <iostream>
#include <array>

int main()
{
    //int arr[3] = {1,2,3}; traditional array

    std::array<int, 3> arr2 = {1,2,3}; //STL array

    int size = arr2.size();
    for(int i=0; i<size; i++)
    {
        std::cout<<arr2[i]<<std::endl;
    }

    std::cout<<"Element at 2nd index: "<<arr2.at(2)<<std::endl;
    std::cout<<"Empty or not: "<<arr2.empty()<<std::endl;
    std::cout<<"front: "<<arr2.front()<<std::endl;
    std::cout<<"Back: "<<arr2.back()<<std::endl;
    std::cout<<"Back: "<<arr2.cbegin()<<std::endl;
    std::cout<<"Back: "<<arr2.cend()<<std::endl;
}