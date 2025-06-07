#include <iostream>

class MyClass 
{
    private:
        float p;
        int t;
        const float r;

    public:
        MyClass(): r(2.5)
        {

        }

        void read(float pa, int ti)
        {
            p = pa;
            t = ti;
        }

        float show()
        {
            return (p*t*r)/100;
        }
};

int main() 
{
    MyClass a;
    a.read(1000,10);
    std::cout<< a.show();

    return 0;
}