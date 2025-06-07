#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> mm;

    //Adding Data
    mm[1] = "Mandeep";
    mm[4] = "Akatsuki's";
    mm[2] = "Thakur";
    mm[5] = "Member";

    mm.insert({3, "is"}); //Different way to add data

    for(auto i:mm)
    {
        std::cout<<i.second<<std::endl;
    }

    mm.erase(2);

    for(auto i:mm)
    {
        std::cout<<i.second<<std::endl;
    }

    auto it = mm.find(5);

    for(auto i=it; i!=mm.end(); i++)
    {
        std::cout<<(*i).first<<std::endl;
    }

    return 0;
}