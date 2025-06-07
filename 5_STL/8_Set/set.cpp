#include <iostream>
#include <set>

int main() {
    // Creating a set of integers
    std::set<int> mySet;

    // Inserting elements into the set
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10); // Duplicate values are ignored

    // Printing the elements of the set
    std::cout << "Set: ";
    for (const auto& elem : mySet) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Checking if an element exists in the set
    int searchElement = 20;
    if (mySet.find(searchElement) != mySet.end()) 
    {
        std::cout << searchElement << " exists in the set" << std::endl;
    } 
    else 
    {
        std::cout << searchElement << " does not exist in the set" << std::endl;
    }

    std::set<int>::iterator it = mySet.find(20);

    std::cout<<"Value present at: "<< *it <<std::endl;

    return 0;
}
