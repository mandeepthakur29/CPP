#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
    //creation
    std::unordered_map<std::string, int> m;

    //insertion (3 methods)

    //1
    std::pair<std::string, int> p = std::make_pair("Thakur", 3);
    m.insert(p);

    //2
    std::pair<std::string,int> pair2("Mandeep",2);
    m.insert(pair2);

    //3
    m["Manu"] = 1;

    m["Manu"] = 4; //It will update the value (refer 21 line)

    //Searching
    std::cout<<m["Manu"]<<std::endl;
    std::cout<<m.at("Mandeep")<<std::endl;

    //std::cout<<m.at("unknownKey")<<std::endl;
    std::cout<< m["unknownKey"]<<std::endl;

    //to check presence
    std::cout<<m.count("bro")<<std::endl;

    //erase
    m.erase("love");
    
    //iterator
    // Declare an iterator 'it' that will be used to traverse through the elements of the unordered_map 'm'.
    // The iterator is initialized to point to the first element in the unordered_map 'm'.
    std::unordered_map<std::string, int>::iterator it = m.begin();

    while(it != m.end()){
        std::cout<<it->first<<": "<<it->second<<std::endl;
        it++;
    }
}