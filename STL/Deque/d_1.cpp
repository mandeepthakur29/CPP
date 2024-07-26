#include <iostream>
#include <deque>

int main()
{
    std::deque<int> d;

    d.push_back(2);
    d.push_front(1);
    d.push_back(3);
    d.push_back(4);

    for(int i:d)
    {
        std::cout<<i<<std::endl;
    }
    std::cout<<std::endl;

    //d.pop_back(); removing element from back
    //d.pop_front(); removing element from front

    std::cout<<"1st Element-> "<<d.at(1)<<std::endl;

    std::cout<<"Empty or not-> "<<d.empty()<<std::endl; //wheteher its empty or not (O or 1).

    d.erase(d.begin(), d.begin() + 1); // erases the elements in the range
}