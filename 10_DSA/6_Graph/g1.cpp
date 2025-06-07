#include <iostream>
#include <unordered_map>
#include <list>

class Graph
{
    public:
        // Adjacency list representation of the graph
        // 'adj' is an unordered map where each key is a node, and the value is a list of nodes it's connected to
        std::unordered_map<int, std::list<int> > adj;

        // Function to add an edge to the graph
        void addEdge(int u, int v, bool direction)
        {
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            // Create an edge from node 'u' to node 'v'
            adj[u].push_back(v);

            // If the graph is undirected, also create an edge from 'v' to 'u'
            if(direction == 0)
            {
                adj[v].push_back(u);
            }
        }

        // Function to print the adjacency list of the graph
        void printAdjList()
        {
            // Iterate over each node in the adjacency list
            for(auto i : adj)
            {
                std::cout << i.first << " -> ";  // Print the node (key) representing the current node
                // Iterate over all the neighbors of the current node
                for(auto j : i.second)  
                {
                    std::cout << j << ", ";  // Print each neighboring node connected to the current node
                }
                std::cout << std::endl;  // Move to the next line after printing all neighbors
            }
        }
};

int main()
{
    int n;  // Variable to store the number of nodes in the graph
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;  // Input the number of nodes

    int m;  // Variable to store the number of edges in the graph
    std::cout << "Enter the number of edges: ";
    std::cin >> m;  // Input the number of edges

    Graph g;  // Create an object of the Graph class

    // Loop to add edges to the graph
    for(int i = 0; i < m; i++)
    {
        int u, v;  // Variables to store the nodes between which the edge is added
        std::cout << "Enter edge (u, v): ";
        std::cin >> u >> v;  // Input the nodes (u, v) between which the edge exists
        
        // Add an undirected edge between node 'u' and node 'v'
        g.addEdge(u, v, 0);
    }

    // Print the graph in the form of an adjacency list
    std::cout << "Adjacency List:" << std::endl;
    g.printAdjList();  // Call the function to print the adjacency list

    return 0;
}
