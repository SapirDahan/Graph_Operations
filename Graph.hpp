/*
 * Author: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph{

    public:
        vector<vector<int>> matrix; // Adjacency matrix representation of the graph

        /**
         * Loads a new graph from an adjacency matrix.
         * @param graph A 2D vector representing an adjacency matrix of the new graph.
         */
        void loadGraph(const vector<vector<int>>& graph);

        /**
         * @return A string representation of the adjacency matrix.
         */
        string printGraphEx1() const;


        /// Helper functions ///

        /**
         * @return The size of the adjacency matrix, which corresponds to the number of vertices in the graph.
         */
        unsigned int size() const;

        /**
         * Retrieves the weight of an edge between two vertices. If no edge exists, returns 0.
         * @param x The source vertex index.
         * @param y The target vertex index.
         * @return The weight of the edge from x to y. Returns 0 or another value indicating no edge if there is no connection between x and y.
         */
        const int getEdge(unsigned int x, unsigned int y) const;

        /**
         * Gets all vertices connected to a given vertex by an edge.
         * @param vertex The index of the vertex for which connected vertices are sought.
         * @return A vector containing indices of all vertices directly connected to the specified vertex.
         */
        vector<unsigned int> getConnectedVertices(unsigned int vertex) const;

        /**
         * Transposes the graph by swapping the rows and columns of the adjacency matrix.
         */
        void transposeGraph();


        /// Project 2 ///
        string printGraph() const;
        Graph operator+(const Graph& other) const;
        Graph operator++() const;
        Graph& operator+=(const Graph& other);
        Graph& operator+();
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph& operator-();
        Graph operator--() const;
        Graph operator*(int factor);
        void operator*=(int factor);
        Graph operator/(int factor);
        void operator/=(int factor);
        Graph operator*(const Graph& other) const;
        void operator*=(const Graph& other);
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph){
            os << graph.printGraph();
            return os;
        }
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        void generateCombinations(vector<vector<unsigned int>>& result, vector<unsigned int>& combination, unsigned int start, unsigned int n, unsigned int m) const;
        vector<vector<unsigned int>> getAllCombinations(unsigned int n, unsigned int m) const;
        int countEdges() const;


        };

}


