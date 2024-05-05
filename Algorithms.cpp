/*
 * Author: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */


#include "Algorithms.hpp"
#include <vector>
#include <climits>
#include <queue> // For Bipartite


using namespace ariel;


// Checking if the graph is strongly connected
bool Algorithms::isConnected(const Graph& graph) {

    const unsigned int graphSize = graph.size(); // Size of the graph

    // A vector that save who we visited
    vector<bool> visited(graphSize, false);

    // Going over all combinations of paths
    for(unsigned int i = 0; i < graphSize; i++) {
        for(unsigned int j = 0; j < graphSize; j++) {

            // We don't need to check if a vertex have a path to himself
            if(i != j) {

                // If there is no path return false because the graph is not strongly connected
                if(!hasPath(graph, i , j, visited)) {
                    return false;
                }

                // Refill the visited vector with false for the next round
                visited.assign(graphSize, false);
            }
        }
    }

    // All paths exist, therefore, our graph is strongly connected
    return true;
}


// Shortest path using the Bellman-Ford algorithm
string Algorithms::shortestPath(const Graph& graph, const unsigned int start, const unsigned int end) {

    const unsigned int numVertices = graph.size(); // Size of the graph

    // Check if the values are in range
    if(start >= numVertices || end >= numVertices) {
        throw invalid_argument("Invalid values: the start and the end vertex should be in range.");
    }

    vector<int> distance(numVertices, INT_MAX); // The distance from the start of each vertex
    vector<int> predecessor(numVertices, -1); // the predecessor of each vertex

    distance[start] = 0; // The distance for the start vertex is 0

    // Relax the edges
    for (unsigned int i = 0; i < numVertices; i++) {
        for (unsigned int j = 0; j < numVertices; j++) {
            for (unsigned int k = 0; k < numVertices; k++) {

                // Checking if edge exist
                if(graph.getEdge(j,k) != 0) {

                    // Check if we can relax it
                    if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {

                        // Change the distance
                        distance[k] = distance[j] + graph.getEdge(j,k);

                        // Change the predecessor
                        predecessor[k] = static_cast<int>(j);
                    }
                }
            }
        }
    }


    // Checking if there is negative cycle in the path between the start and end
    for (unsigned int j = 0; j < numVertices; j++) {
        for (unsigned int k = 0; k < numVertices; k++) {

                // Checking if edge exist
                if(graph.getEdge(j,k) != 0) {

                // Checking if we can relax one more time
                if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {

                    // If we succeeded to relax then there is a negative cycle in the path
                    return "Negative cycle detected in the path.";
                }
            }
        }
    }

    // We failed to reach the end vertex, therefore, there is no path
    if (distance[static_cast<unsigned int>(end)] == INT_MAX) {
        return "-1";
    }

    // Reconstruct the path
    string path = to_string(end);

    // Go over the vertex from the end to the start with predecessor to reconstruct the path
    for (unsigned int current = end; current != start; current = static_cast<unsigned int>(predecessor[current])) {
        path.insert(0, "->");
        path.insert(0, to_string(predecessor[current]));
    }

    // Return the path
    return path;
}

// Find out if the graph contain cycle. If it does then return the cycle
string Algorithms::isContainsCycle(const Graph& graph) {

    const unsigned int numVertices = graph.size(); // Graph size

    // Visited vertexes
    vector<bool> visited(numVertices, false);

    // The predecessor of each vertex it set to the maximum number
    vector<unsigned int> predecessor(numVertices, INT_MAX);

    // The path of the cycle
    string cyclePath = "";

    // If we hadn't visited the vertex check if it is on a cycle
    for (unsigned int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (DFSForDetectingCycles(i, INT_MAX, graph, visited, predecessor, cyclePath)) {

                // Check if the cycle has at least 3 different nodes
                // Only then we will call it a cycle
                if (countOccurrences(cyclePath, '>') >= 2) {
                    return cyclePath;
                }

                else {
                    // Reset for next iteration
                    cyclePath = "";
                    fill(visited.begin(), visited.end(), false);
                }
            }
        }
    }

    // No cycle found
    return "0";
}


// Finding out if a graph is bipartite
// A graph is bipartite only and only if it 2 colorable
string Algorithms::isBipartite(const Graph& graph) {

    const unsigned int numVertices = graph.size(); // Graph size

    // The color of each vertex. If the color is -1 we haven't determined the color, yet
    // We will use the colors 1 and 2
    vector<int> color(numVertices, -1);

    //The set 'A' will contain the vertex with color 1
    //The set 'B' will contain the vertex with color 2
    unordered_set<unsigned int> A, B;

    string result = ""; // The string result

    // Go over all the vertexes and find out if we had colored them.
    for (unsigned int i = 0; i < numVertices; i++) {
        if (color[i] == -1) {

            if (!BFSForBipartite(graph, i, color, A, B)) {
                return "The graph is not bipartite"; // Not bipartite
            }
        }
    }

    // Format the result and return them
    formatBipartiteSets(A, B, result);
    return result;
}

// Find out if there is negative cycle in the path
string Algorithms::negativeCycle(const Graph& graph) {

    const unsigned int numVertices = graph.size(); // The size of the graph

    // We will check if there is a negative cycle in the shortest path from each vertex to himself.
    // If the vertex on negative cycle the shortest will return there is a negative cycle in the path.
    for(unsigned int i = 0; i < numVertices; i++) {
        if(shortestPath(graph, i, i) == "Negative cycle detected in the path.") {

            // There is a negative cycle in the path
            return "The graph contains negative cycle";
        }
    }

    // There is no negative cycle in the graph
    return "The graph NOT contains negative cycle";
}

/////// Help functions ///////

// Help recursive function to find out if 2 vertex have a path
bool Algorithms::hasPath(const Graph& graph, unsigned int start, unsigned int end, std::vector<bool>& visited) {

    // Mark the current vertex as visited
    visited[start] = true;

    // Base case: If we reach the destination vertex, return true
    if (start == end) {
        return true;
    }

    // Recursive step: Explore all adjacent vertices of the start vertex
    const vector<unsigned int>& edges = graph.getConnectedVertices(start);

    // Going over all the edges
    for (unsigned int adjacentVertex : edges) {

        // Recursively call hasPath for unvisited adjacent vertices
        if (!visited[adjacentVertex]) {
            if (hasPath(graph, adjacentVertex, end, visited)) {
                return true; // If a path is found, return true
            }
        }
    }

    // If we reach here, there is no path from start vertex to end vertex
    return false;
}

// Help function that go recursively over the graph to detect cycle
bool Algorithms::DFSForDetectingCycles(const unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& visited, vector<unsigned int>& parent, string& cyclePath) {

    visited[node] = true; // We visited the node
    parent[node] = parentNode; // The parent of the node

    // Go over the connected vertexes of the node
    for (const unsigned int nextNode : graph.getConnectedVertices(node)) {

        // If we hadn't visited the node
        if (!visited[nextNode]) {
            if (DFSForDetectingCycles(nextNode, node, graph, visited, parent, cyclePath)) {
                return true; // There is a cycle
            }
        }

        // We found a cycle which is not get 2 vertexes
        else if (nextNode != parentNode) {

            unsigned int current = node;

            //The cycle is:
            cyclePath = "The cycle is: " + to_string(nextNode); // Initialize cyclePath with the last vertex in the cycle

            // Go over the vertexes and add them to the path
            while (current != INT_MAX && current != nextNode) {
                cyclePath += "->" + std::to_string(current); // Append current vertex to the end
                current = parent[current];
            }

            cyclePath += "->" + to_string(nextNode); // Append the last vertex again to close the cycle

            //There is a cycle
            return true;
        }
    }

    // There is no cycle in the graph
    return false;
}

// Go over the graph with BFS and color it if possible
bool Algorithms::BFSForBipartite(const Graph& graph, const unsigned int start, vector<int>& color, unordered_set<unsigned int>& A, unordered_set<unsigned int>& B) {

    queue<unsigned int> q; // Set queue

    // This queue will save all the vertex we still hadn't visited all there neighbors

    q.push(start); // Push the start vertex to the queue

    // Checking if the vertex have neighbors in 'A' or 'B'
    // If it has neighbors in both then the graph is not bipartite
    bool neighborsInA = false;
    bool neighborsInB = false;

    for(const unsigned int startNeighbors : graph.getConnectedVertices(start)) {
        if (color[startNeighbors] == 1) {
            neighborsInA = true;
        }
        if (color[startNeighbors] == 2) {
            neighborsInB = true;
        }
    }

    // Impossible to 2 color the graph
    if (neighborsInA && neighborsInB) {
        return false;
    }

    // We have to color the start vertex 2
    if(neighborsInA) {
        color[static_cast<unsigned int>(start)] = 2; // Assign the first color
        B.insert(start);
    }

    // We will color the start vertex 1 otherwise
    else {
        color[start] = 1; // Assign the first color
        A.insert(start);
    }


    // While the queue is not empty
    while (!q.empty()) {

        // Get and pop the first element in the queue
        unsigned int currVertex = q.front();
        q.pop();

        // Go over all the vertexes connected to the current vertex
        for (const unsigned int nextVertex : graph.getConnectedVertices(currVertex)) {

            // If we hadn't colored the vertex
            if (color[nextVertex] == -1) {

                // Set the color
                color[nextVertex] = 3 - color[currVertex]; // Assign the opposite color

                // Add to the correct ser
                if(color[nextVertex] == 1) {
                    A.insert(nextVertex);
                }

                else {
                    B.insert(nextVertex);
                }

                // Push the next vertex to the queue
                q.push(nextVertex);
            }

            // If the next vertex have the same color of the current vertex then it is not 2 colorable
            else if (color[nextVertex] == color[currVertex]) {
                return false; // Not bipartite
            }
        }
    }

    return true; // Bipartite
}

// Get elements and construct a string representing the set
string Algorithms::setToString(const unordered_set<unsigned int>& s) {

    string str;

    // Go over the elements in the set
    for (const unsigned int elem : s) {
        str = ", " + to_string(elem) + str;
    }

    // Erase the first two characters
    if (!str.empty()) {
        str.erase(0, 2);
    }

    // Return the string
    return str;
}


// Construct the string representing the 2 set
void Algorithms::formatBipartiteSets(const unordered_set<unsigned int>& A, const unordered_set<unsigned int>& B, string& result) {
    result = "The graph is bipartite: A={";
    result.append(setToString(A));
    result.append("}, B={");
    result.append(setToString(B));
    result.append("}.");
}


// Count how many times a char appears in a string
unsigned int Algorithms::countOccurrences(const std::string& str, char target) {

    unsigned int count = 0;

    // Go over the string
    for (const char ch : str) {
        if (ch == target) {
            count++;
        }
    }

    return count;
}

