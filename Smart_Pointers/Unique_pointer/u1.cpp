#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> ptr1 = std::make_unique<int>(25); //unique pointers can't be shared or copied to another.

    //std::unique_ptr<int> ptr2 = ptr1; //not possible. But, we can move it instead of copy. See below, How...

    std::unique_ptr<int> ptr2 = std::move(ptr1);

    std::cout<<*ptr2;
    //std::cout<<*ptr1; -> now it becomes NULL pointer.

    return 0;
}