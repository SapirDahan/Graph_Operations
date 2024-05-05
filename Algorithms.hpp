/*
 * Author: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */


#pragma once

#include "Graph.hpp"
#include <unordered_set> // For checking if a graph is bipartite

using namespace std;

namespace ariel {
    class Algorithms {
    public:
        /**
         * Checks if the graph is strongly connected.
         * @param graph The graph to check.
         * @return True if the graph is strongly connected, false otherwise.
         */
        static bool isConnected(const Graph& graph);

        /**
         * Finds the shortest path between two vertices using the Bellman-Ford algorithm.
         * @param graph The graph to analyze.
         * @param start The starting vertex index.
         * @param end The ending vertex index.
         * @return A string representation of the shortest path, if exists.
         */
        static string shortestPath(const Graph& graph, unsigned int start, unsigned int end);

        /**
         * Determines if the graph contains any cycle.
         * @param graph The graph to check.
         * @return A string indicating the presence or absence of a cycle.
         */
        static string isContainsCycle(const Graph& graph);

        /**
         * Checks if the graph is bipartite.
         * @param graph The graph to check.
         * @return A string indicating whether the graph is bipartite or not.
         */
        static string isBipartite(const Graph& graph);

        /**
         * Detects the presence of a negative cycle in the graph.
         * @param graph The graph to analyze.
         * @return A string representation whether a negative cycle exist.
         */
        static string negativeCycle(const Graph& graph);

    private:
        /**
         * Helper function to check if there is a path between two vertices.
         * @param graph The graph to analyze.
         * @param start The starting vertex index.
         * @param end The ending vertex index.
         * @param visited A reference to a vector indicating if a vertex has been visited.
         * @return True if a path exists, false otherwise.
         */
        static bool hasPath(const Graph& graph, unsigned int start, unsigned int end, vector<bool>& visited);

        /**
         * Performs depth-first search (DFS) to detect cycles in the graph.
         * @param node The current node being visited.
         * @param parentNode The parent node of the current node.
         * @param graph The graph being analyzed.
         * @param visited A reference to a vector indicating if a vertex has been visited.
         * @param parent A reference to a vector storing the parent of each vertex.
         * @param cyclePath A reference to a string that will contain the cycle path if found.
         * @return True if a cycle is detected, false otherwise.
         */
        static bool DFSForDetectingCycles(unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& visited, vector<unsigned int>& parent, string& cyclePath);

        /**
         * Performs breadth-first search (BFS) to check if the graph is bipartite.
         * @param graph The graph to analyze.
         * @param start The starting vertex index for BFS.
         * @param color A reference to a vector storing the color of each vertex.
         * @param A A reference to an unordered set representing one set of vertices in the bipartite graph.
         * @param B A reference to an unordered set representing the other set of vertices in the bipartite graph.
         * @return True if the graph is bipartite, false otherwise.
         */
        static bool BFSForBipartite(const Graph& graph, unsigned int start, vector<int>& color, unordered_set<unsigned int>& A, unordered_set<unsigned int>& B);

        /**
         * Formats the sets of vertices in a bipartite graph into a string representation.
         * @param A An unordered set representing one set of vertices in the bipartite graph.
         * @param B An unordered set representing the other set of vertices in the bipartite graph.
         * @param result A reference to a string that will contain the formatted result.
         */
        static void formatBipartiteSets(const unordered_set<unsigned int>& A, const unordered_set<unsigned int>& B, string& result);

        /**
         * Converts an unordered set of unsigned integers into a comma-separated string.
         * @param s The set to convert.
         * @return A string representation of the set.
         */
        static string setToString(const unordered_set<unsigned int>& s);

        /**
         * Counts occurrences of a target character in a given string.
         * @param str The string to search in.
         * @param target The character to count occurrences of.
         * @return The number of occurrences of the target character in the string.
         */
        static unsigned int countOccurrences(const string& str, char target);
    };
}