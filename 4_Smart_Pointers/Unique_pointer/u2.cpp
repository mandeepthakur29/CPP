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
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(); //object created of type "MyClass".

    return 0;
}

// When a std::unique_ptr goes out of scope, its destructor is automatically called, and it in turn 
// deletes the dynamically allocated memory it owns. In this case, ptr1 owns an object of type MyClass 
// created by std::make_unique<MyClass>(). When ptr1 goes out of scope, its destructor is called, and 
// it deletes the dynamically allocated MyClass object, which results in the invocation of the destructor 
// of MyClass.