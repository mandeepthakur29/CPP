#include <iostream>
#include <stack>

int main()
{
    std::stack<std::string> s; //stack<string> s; it means without "using namespace std;".

    s.push("Itachi");
    s.push("A.K.A");
    s.push("Thakur");
    s.push("Mandeep"); //last element to put, but placed at top. It will come out first.

    std::cout<<"Top Element: "<<s.top()<<std::endl;

    return 0;
}

//LIFO -> Jo sabse last m jaaega, wo sabse phle niklega.
//Example -> Stack of Plates palced on a table.