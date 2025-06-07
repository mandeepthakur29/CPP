#include <iostream>

void printPairs(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << "(" << i << ", " << j << ") ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 3;
    std::cout << "Pairs from 1 to " << n << ":" << std::endl;
    printPairs(n);
    return 0;
}

// In this example, the printPairs function generates and prints all possible pairs of numbers from 1 to n. It achieves this 
// by using nested loops: one loop iterates from 1 to n (inclusive) to represent the first element of each pair, and the other 
// loop also iterates from 1 to n (inclusive) to represent the second element of each pair.

// As a result, the total number of pairs printed is n * n, which results in a time complexity of O(n^2). This is because for 
// each value of the outer loop, the inner loop runs n times, leading to a total of n * n iterations.

//While, in O(n^3) example, nested loop will be 3 and so on...