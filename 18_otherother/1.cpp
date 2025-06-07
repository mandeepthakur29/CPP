#include <iostream>
using namespace std;

class Base {
    public:
    Base(){}
    ~Base(){}
    virtual void Display()
    {
        cout<<"Base class"<<endl;
    }
};
 
class Derived : public Base {
    public:
    Derived() {}
    ~Derived() {}
    void Display()
    {
        cout<<"Derived class"<<endl;
    }
};
 
int main() {
 
Base *ptr = new Derived();
ptr->Display();
 
return 0;
}