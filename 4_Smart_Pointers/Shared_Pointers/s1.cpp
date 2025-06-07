#include <iostream>
#include <memory>

class MyClass
{
    public:
        MyClass()
        {
            std::cout<<"Constructor Invoked."<<std::endl;
        }

        ~MyClass()
        {
            std::cout<<"Destructor Invoked."<<std::endl;
        }
};

int main()
{
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(); //object created of type "MyClass".
    std::cout<<"Shared Point: "<<ptr1.use_count()<<std::endl;

    std::shared_ptr<MyClass> ptr2 = ptr1; //shared
    std::cout<<"Shared Point: "<<ptr1.use_count()<<std::endl; //shared count increased

    return 0;
}