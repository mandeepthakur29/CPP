#include <iostream>
#include <vector>

// Function to print each element of a vector
void printElements(const std::vector<int>& vec) 
{
    int n = vec.size();
    for (int i = 0; i < n; ++i) 
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Print each element of the vector
    printElements(numbers);

    return 0;
}

// In this example, the function printElements() iterates over each element of a vector vec and prints it. The loop runs for n 
// iterations, where n is the size of the vector. Therefore, the time complexity of the printElements() function is O(n). As the 
// size of the vector increases, the runtime of the function grows linearly with the size of the vector.