#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v; //initializing a empty vector with size 0

    std::vector<int> a(5,1); //initializes a vector with 5 elements, each initialized to the value 1.

    std::vector<int> last(a); //copy all elements of "a" into "last".

    std::cout<<"Capacity-> "<<v.capacity()<<std::endl;

    v.push_back(10);
    std::cout<<"Capacity-> "<<v.capacity()<<std::endl;

    v.push_back(20);
    std::cout<<"Capacity-> "<<v.capacity()<<std::endl;

    v.push_back(30);
    std::cout<<"Capacity-> "<<v.capacity()<<std::endl;

    std::cout<<"Size-> "<<v.size()<<std::endl;

    std::cout<<"Element at 2nd index->"<<v.at(2)<<std::endl;

    for(int i:v) //loop to print elements
    {
        std::cout<<i<<" ";
    }   
    std::cout<<std::endl;

    v.pop_back(); //deleting a element from last

    for(int i:v) //loop to print elements
    {
        std::cout<<i<<" ";
    }   
    std::cout<<std::endl;

    v.clear(); //keep in mind, it remove the elements, thus size becomes 0, but capacity remains same.
}

// Size: The size of a vector is the number of elements it currently holds.

// Capacity: The capacity of a vector is the amount of memory allocated to store the elements of the vector.