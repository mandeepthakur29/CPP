#include <iostream>
#include <string>

struct YouTubeChannel 
{
    std::string Name;
    int SubscribersCount;

public:
    // Constructor
    YouTubeChannel(std::string name, int subscribersCount) : Name(name), SubscribersCount(subscribersCount) {}
};

// Overloaded insertion operator implementation
std::ostream &operator<<(std::ostream &out, const YouTubeChannel &ytChannel) 
{
    out << "Name: " << ytChannel.Name << std::endl;
    out <<"Break."<<std::endl; //details are printing in this function, not in line 28
    out << "Subscribers: " << ytChannel.SubscribersCount << std::endl;
    return out;
}

int main() {
    // Create a YouTubeChannel object
    YouTubeChannel channel("ExampleChannel", 1000);

    // Output the channel details using overloaded insertion operator
    std::cout << channel;

    return 0;
}
