#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    vector<list<int>> adjLists; // Vector of lists for adjacency lists
    vector<bool> visited;        // Vector to track visited vertices

public:
    // Constructor to initialize the graph
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void resetVisited();  // Utility function to reset visited nodes
};

// Initialize graph with given number of vertices
Graph::Graph(int vertices) : numVertices(vertices), adjLists(vertices), visited(vertices, false) {}

// Add an edge to the graph (for directed graphs)
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

// Recursive DFS function
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    // Visit all unvisited adjacent vertices
    for (int adjVertex : adjLists[vertex]) {
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
    }
}

// Reset the visited array to reuse the DFS traversal
void Graph::resetVisited() {
    fill(visited.begin(), visited.end(), false);
}

// Main function to demonstrate DFS
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "DFS traversal starting from vertex 2:\n";
    g.DFS(2);

    cout << "\n\nResetting visited vertices and running DFS from vertex 0:\n";
    g.resetVisited();
    g.DFS(0);

    return 0;
}
