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

        vector<vector<int>> matrix; // Adjacency matrix representation of the graph

    public:

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

        /**
         * Overload for the addition operator (+) to combine two graphs.
         *
         * This operator overloads the addition operator (+) to merge two graphs into a new graph.
         *
         * @param other The graph to be added to the current graph.
         * @return The result of adding the two graphs.
         */
        Graph operator+(const Graph& other) const;

        /**
         * Overload for the pre-increment operator (++) to increment all non-zero elements of the graph by 1.
         *
         * This operator overloads the pre-increment operator (++) to increment all non-zero elements of the graph by 1.
         *
         * @return The graph with all non-zero elements incremented by 1.
         */
        Graph operator++(int);

        /**
         * Overload for the addition-assignment operator (+=) to add another graph to the current graph.
         *
         * This operator overloads the addition-assignment operator (+=) to add another graph to the current graph.
         *
         * @param other The graph to be added to the current graph.
         */
        void operator+=(const Graph& other);

        /**
         * Overload for the unary plus operator (+) to return a copy of the current graph.
         *
         * This operator overloads the unary plus operator (+) to return a copy of the current graph.
         *
         * @return A copy of the current graph.
         */
        Graph& operator+();

        /**
         * Overload for the subtraction operator (-) to subtract another graph from the current graph.
         *
         * This operator overloads the subtraction operator (-) to subtract another graph from the current graph.
         *
         * @param other The graph to be subtracted from the current graph.
         * @return The result of subtracting the two graphs.
         */
        Graph operator-(const Graph& other) const;

        /**
         * Overload for the subtraction-assignment operator (-=) to subtract another graph from the current graph.
         *
         * This operator overloads the subtraction-assignment operator (-=) to subtract another graph from the current graph.
         *
         * @param other The graph to be subtracted from the current graph.
         */
        void operator-=(const Graph& other);

        /**
         * Overload for the unary minus operator (-) to negate all elements of the graph.
         *
         * This operator overloads the unary minus operator (-) to negate all elements of the graph.
         */
        Graph& operator-();

        /**
         * Overload for the post-decrement operator (--) to decrement all non-zero elements of the graph by 1.
         *
         * This operator overloads the post-decrement operator (--) to decrement all non-zero elements of the graph by 1.
         *
         * @return The graph with all non-zero elements decremented by 1.
         */
        Graph operator--(int);

        /**
         * Overload for the scalar multiplication operator (*) to multiply each element of the graph by a scalar value.
         *
         * This operator overloads the scalar multiplication operator (*) to multiply each element of the graph by a scalar value.
         *
         * @param factor The scalar value by which to multiply each element of the graph.
         * @return The result of multiplying each element of the graph by the scalar value.
         */
        Graph operator*(int factor) const;

        /**
         * Overload for the scalar multiplication-assignment operator (*=) to multiply each element of the graph by a scalar value.
         *
         * This operator overloads the scalar multiplication-assignment operator (*=) to multiply each element of the graph by a scalar value.
         *
         * @param factor The scalar value by which to multiply each element of the graph.
         */
        void operator*=(int factor);

        /**
         * Overload for the scalar division operator (/) to divide each element of the graph by a scalar value.
         *
         * This operator overloads the scalar division operator (/) to divide each element of the graph by a scalar value.
         *
         * @param factor The scalar value by which to divide each element of the graph.
         * @return The result of dividing each element of the graph by the scalar value.
         */
        Graph operator/(int factor) const;

        /**
         * Overload for the scalar division-assignment operator (/=) to divide each element of the graph by a scalar value.
         *
         * This operator overloads the scalar division-assignment operator (/=) to divide each element of the graph by a scalar value.
         *
         * @param factor The scalar value by which to divide each element of the graph.
         */
        void operator/=(int factor);

        /**
         * Overload for the matrix multiplication operator (*) to multiply two graphs.
         *
         * This operator overloads the matrix multiplication operator (*) to perform matrix multiplication between two graphs.
         *
         * @param other The graph to be multiplied with the current graph.
         * @return The result of multiplying the two graphs.
         */
        Graph operator*(const Graph& other) const;

        /**
         * Overload for the matrix multiplication-assignment operator (*=) to multiply the current graph by another graph.
         *
         * This operator overloads the matrix multiplication-assignment operator (*=) to multiply the current graph by another graph.
         *
         * @param other The graph to be multiplied with the current graph.
         */
        void operator*=(const Graph& other);

        /**
         * Overload for the output stream operator (<<) to output the graph.
         *
         * This friend function overloads the output stream operator (<<) to output the graph by printing its adjacency matrix representation.
         *
         * @param os The output stream where the graph will be printed.
         * @param graph The graph object to be printed.
         * @return The output stream after printing the graph.
         */
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
            os << graph.printGraph();
            return os;
        }

        /**
         * Overload for the equality operator (==) to check if two graphs are equal.
         *
         * This operator overloads the equality operator (==) to compare if two graphs are equal.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the graphs are equal, false otherwise.
         */
        bool operator==(const Graph& other) const;

        /**
         * Overload for the inequality operator (!=) to check if two graphs are not equal.
         *
         * This operator overloads the inequality operator (!=) to compare if two graphs are not equal.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the graphs are not equal, false otherwise.
         */
        bool operator!=(const Graph& other) const;

        /**
         * Overload for the less than operator (<) to check if one graph is less than another.
         *
         * This operator overloads the less than operator (<) to compare if one graph is less than another.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the current graph is less than the other graph, false otherwise.
         */
        bool operator<(const Graph& other) const;

        /**
         * Overload for the less than or equal to operator (<=) to check if one graph is less than or equal to another.
         *
         * This operator overloads the less than or equal to operator (<=) to compare if one graph is less than or equal to another.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the current graph is less than or equal to the other graph, false otherwise.
         */
        bool operator<=(const Graph& other) const;

        /**
         * Overload for the greater than operator (>) to check if one graph is greater than another.
         *
         * This operator overloads the greater than operator (>) to compare if one graph is greater than another.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the current graph is greater than the other graph, false otherwise.
         */
        bool operator>(const Graph& other) const;

        /**
         * Overload for the greater than or equal to operator (>=) to check if one graph is greater than or equal to another.
         *
         * This operator overloads the greater than or equal to operator (>=) to compare if one graph is greater than or equal to another.
         *
         * @param other The graph to be compared with the current graph.
         * @return True if the current graph is greater than or equal to the other graph, false otherwise.
         */
        bool operator>=(const Graph& other) const;

        /**
         * Print the adjacency matrix representation of the graph.
         *
         * This function generates a string representation of the adjacency matrix of the graph for printing purposes.
         *
         * @return A string representing the adjacency matrix of the graph.
         */
        std::string printGraph() const;

    private:
        /**
         * Recursive function to generate combinations in ascending order.
         *
         * This function recursively generates combinations of choosing n elements in ascending order from a set of size m.
         *
         * @param result The vector to store all generated combinations.
         * @param combination The current combination being built.
         * @param start The starting index for choosing elements.
         * @param n The number of elements to choose.
         * @param m The total number of elements in the set.
         */
        void generateCombinations(std::vector<std::vector<unsigned int>>& result, std::vector<unsigned int>& combination, unsigned int start, unsigned int n, unsigned int m) const;

        /**
         * Get all combinations of choosing n elements from a set of size m in ascending order.
         *
         * This function returns all combinations of choosing n elements from a set of size m in ascending order.
         *
         * @param n The number of elements to choose.
         * @param m The total number of elements in the set.
         * @return A vector containing all generated combinations.
         */
        std::vector<std::vector<unsigned int>> getAllCombinations(unsigned int n, unsigned int m) const;

        /**
         * Count the number of edges in the graph.
         *
         * This function counts and returns the total number of edges in the graph.
         *
         * @return The total number of edges in the graph.
         */
        int countEdges() const;

    };
}


