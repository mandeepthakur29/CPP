#include <iostream>
#include <vector>

std::pair<int, int> findNumber(std::vector<std::vector<int>>& matrix, int target) {
    int rows = matrix.size();

    int cols = matrix[0].size();

    int row = 0;
    int col = 0; // Start from the top-left corner

    while (row < rows && col < cols) {
        if (matrix[row][col] == target) {
            return {row, col}; // Found the target
        } else if (matrix[row][col] < target) {
            col++; // Move right in the same row
        } else {
            row++; // Move down to the next row
        }
    }

    // Check the last element in the last row
    if (matrix[rows - 1][cols - 1] == target) {
        return {rows - 1, cols - 1}; // Found the target
    }

    return {-1, -1}; // Target not found
}

int main() {
    // Example usage
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;
    std::pair<int, int> result = findNumber(matrix, target);
    std::cout << "Target found at position: (" << result.first << ", " << result.second << ")\n";

    return 0;
}
