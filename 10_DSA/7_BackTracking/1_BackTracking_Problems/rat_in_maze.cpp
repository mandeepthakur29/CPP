#include <iostream>
#include <vector>
#include <string>

// Function to check if the new position (newX, newY) is within bounds, not visited, and a valid move
bool isSafe(int newX, int newY, std::vector<std::vector<bool> > &vis, std::vector<std::vector<int> > &arr, int n)
{
    // Check if newX and newY are inside the maze boundaries
    // Check if the position has not been visited yet
    // Check if the cell contains 1 (which means the path is open and not blocked)
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) &&
        !vis[newX][newY] && arr[newX][newY] == 1)
    {
        return true; // Safe to move to this position
    }
    else
    {
        return false; // Not a valid or safe move
    }
}

// Recursive function to explore all possible paths from (x, y) to (n-1, n-1)
void solve(int x, int y, std::vector<std::vector<int> > &arr, int n, std::vector<std::string> &ans,
           std::vector<std::vector<bool> > &vis, std::string path)
{
    // Base case: if the rat reaches the destination (bottom-right corner of the maze)
    if (x == n - 1 && y == n - 1)
    {
        // Add the current path string to the answer vector
        ans.push_back(path);
        return;
    }

    // Mark the current cell (x, y) as visited to avoid revisiting
    vis[x][y] = true; 

    // Move Down: Try moving to the cell directly below (x+1, y)
    if (isSafe(x + 1, y, vis, arr, n))
    {
        // If the move is safe, append 'D' (for Down) to the path and recursively move to (x+1, y)
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    // Move Left: Try moving to the cell to the left (x, y-1)
    if (isSafe(x, y - 1, vis, arr, n))
    {
        // If the move is safe, append 'L' (for Left) to the path and recursively move to (x, y-1)
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    // Move Right: Try moving to the cell to the right (x, y+1)
    if (isSafe(x, y + 1, vis, arr, n))
    {
        // If the move is safe, append 'R' (for Right) to the path and recursively move to (x, y+1)
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    // Move Up: Try moving to the cell directly above (x-1, y)
    if (isSafe(x - 1, y, vis, arr, n))
    {
        // If the move is safe, append 'U' (for Up) to the path and recursively move to (x-1, y)
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    // Backtrack: Unmark the current cell as visited to allow other paths to explore it
    vis[x][y] = false;
}

// Function to return all the paths from the top-left corner to the bottom-right corner of the maze
std::vector<std::string> searchMaze(std::vector<std::vector<int> > &arr, int n)
{
    std::vector<std::string> ans;                   // To store all valid paths found
    std::vector<std::vector<bool> > visited(n, std::vector<bool>(n, false)); // To keep track of visited cells (all initially false)
    std::string path = "";                          // This will hold the current path being explored

    // Check if the start position (0,0) is blocked (contains 0)
    // If the start is blocked, return an empty answer since there's no valid path
    if (arr[0][0] == 0)
        return ans;

    // Call the recursive function to explore all paths starting from the top-left corner (0,0)
    solve(0, 0, arr, n, ans, visited, path);

    return ans; // Return the vector containing all valid paths
}

// Driver function
int main()
{
    int n = 4; // Size of the maze (4x4 in this case)

    // Define the maze as a 2D vector of integers where:
    // 1 represents an open path, and 0 represents a blocked path
    std::vector<std::vector<int> > maze = {{1, 0, 0, 0},
                                          {1, 1, 0, 1},
                                          {0, 1, 0, 0},
                                          {1, 1, 1, 1}};

    // Call the searchMaze function to get all the valid paths
    std::vector<std::string> result = searchMaze(maze, n);

    // Check if any valid paths were found
    if (result.size() == 0)
    {
        // If no paths were found, print "No path found!"
        std::cout << "No path found!" << std::endl;
    }
    else
    {
        // Otherwise, print all the paths that were found
        for (std::string path : result)
        {
            std::cout << path << std::endl; // Each path is represented as a string of directions (D, L, R, U)
        }
    }

    return 0;
}
