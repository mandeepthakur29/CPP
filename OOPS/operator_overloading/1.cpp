// [return datatype] fun_name(argument_list) :- syntax for simple function

// [return datatype] operator symbol(argument list) :- syntax for operator overloading function

#include <iostream>

class Test
{
    int a;

    public:
        void get()
        {
            std::cin>>a;
        }

        void compare(Test t2)
        {
            if(a == t2.a)
            {
                std::cout<<"Both are equal."<<std::endl;
            }
            else
            {
                std::cout<<"Not equal."<<std::endl;
            }
        }
};

int main()
{
    Test t1, t2;

    std::cout<<"Enter t1's object value: ";
    t1.get();

    std::cout<<"Enter t2's object value: ";
    t2.get();

    t1.compare(t2);

    return 0;
}