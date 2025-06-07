#include <iostream>
#include <vector>

// This function adds the current board configuration to the list of solutions (ans)
void addSolution(std::vector<std::vector<int> > &board, std::vector<std::vector<int> > &ans, int n)
{
    // Create a temporary array to store the current board configuration
    std::vector<int> temp;

    // Traverse the entire board and add each element to the temp vector
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // Append the board element at (i, j) to temp
            temp.push_back(board[i][j]);
        }
    }

    // After storing the current board configuration in temp, push it into the ans vector
    ans.push_back(temp);
}

// This function checks if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, std::vector<std::vector<int> > &board, int n)
{
    int x = row;
    int y = col;

    // Check horizontally to the left (same row, previous columns) for any queens
    while(y >= 0)
    {
        if(board[x][y] == 1)  // If there's a queen in the same row on the left
            return false;     // It's not safe to place a queen in this column
        y--;
    }

    // Reset x and y for diagonal checks
    x = row;
    y = col;

    // Check the upper-left diagonal for any queens
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)  // If a queen is found in the upper-left diagonal
            return false;     // It's not safe to place a queen in this column
        x--;
        y--;
    }

    // Reset x and y again for checking the lower-left diagonal
    x = row;
    y = col;

    // Check the lower-left diagonal for any queens
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1)  // If a queen is found in the lower-left diagonal
            return false;     // It's not safe to place a queen in this column
        x++;
        y--;
    }

    // If no queens are found in the left, upper-left diagonal, or lower-left diagonal,
    // it's safe to place a queen at (row, col)
    return true;
}

// This recursive function attempts to place queens in all columns starting from the current column 'col'
void solve(int col, std::vector<std::vector<int> > &ans, std::vector<std::vector<int> > &board, int n)
{
    // Base case: If all queens are placed (col == n), a solution is found
    if(col == n)
    {
        // Add the current board configuration to the list of solutions
        addSolution(board, ans, n);
        return;
    }

    // Iterate over each row in the current column and try placing a queen
    for(int row = 0; row < n; row++)
    {
        // Check if it's safe to place a queen at (row, col)
        if(isSafe(row, col, board, n))
        {
            // Place a queen at (row, col) by setting board[row][col] = 1
            board[row][col] = 1;

            // Recursively try to place queens in the next column (col + 1)
            solve(col + 1, ans, board, n);

            // Backtrack: Remove the queen from (row, col) to try other positions
            board[row][col] = 0;
        }
    }
}

// This function solves the N-Queens problem and returns all possible solutions
std::vector<std::vector<int> > nQueens(int n)
{
    // Initialize the chessboard as a 2D vector of size n x n, filled with 0s (no queens placed initially)
    std::vector<std::vector<int> > board(n, std::vector<int>(n, 0));

    // Initialize a vector to store all the solutions
    std::vector<std::vector<int> > ans;

    // Start solving the N-Queens problem from the first column (col = 0)
    solve(0, ans, board, n);

    // Return the vector containing all solutions
    return ans;
}


// Main function to run the N-Queens solution
int main()
{
    int n;
    std::cout << "Enter the value of N: ";
    std::cin >> n;

    std::vector<std::vector<int> > solutions = nQueens(n);

    std::cout << "Number of solutions: " << solutions.size() << std::endl;
    
    // Print all solutions
    for(int i = 0; i < solutions.size(); i++)
    {
        std::cout << "Solution " << i+1 << ":\n";
        for(int j = 0; j < n*n; j++)
        {
            std::cout << solutions[i][j] << " ";
            if((j + 1) % n == 0)  // Print the next row after every n elements
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}