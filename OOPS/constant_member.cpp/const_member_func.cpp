#include <iostream>

class MyClass 
{
    private:
        int a, b;
    public:
        void read()
        {
            a = 10;
            b = 20;
        }

        void show() const //with const, i can't change any value inside this function, that is already defined. 
        {
            //a = 30;
            //b = 40;

            int c = 50; //c is not defined previously, so I can assign any value here. 

            std::cout<<"a and b are: "<<a<<", "<<b<<std::endl;
        }
};

int main() 
{
    MyClass a;
    
    a.read();
    a.show();

    return 0;
}