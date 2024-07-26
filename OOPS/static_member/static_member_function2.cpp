#include <iostream>

class MyClass 
{
    public:
        static void bigNum(int x, int y);
};

int main() 
{
    MyClass a;
    
    a.bigNum(2,3);

    MyClass::bigNum(5,4);

    return 0;
}

void MyClass::bigNum(int x, int y)
{
    {
            if(x > y)
            {
                std::cout<<"X is bigger."<<std::endl;
            }
            else if(y > x)
            {
                std::cout<<"y is bigger."<<std::endl;
            }
            else
                std::cout<<"Both are equal."<<std::endl;
        }
}
