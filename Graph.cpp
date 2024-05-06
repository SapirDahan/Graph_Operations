/*
 * Author: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */

#include "Graph.hpp"

using namespace ariel;


// Load the graph and check if it squares also no edge between a vertex to himself
void Graph::loadGraph(const std::vector<std::vector<int>>& graph){

    // Check the matrix is square
    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        // No edges allowed between the vertex to himself
		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph: No edges allowed between the vertex to himself.");
		}
    }
    // Assign the graph to the matrix member variable
    matrix = graph;
}

// Return how many vertex and edge the graph have
string Graph::printGraphEx1() const {
    int edges = 0;

    // counting the edges
    for (const auto& edge : matrix) {
        for (int num : edge) {
            if (num != 0) {
                edges++;
            }
        }
    }

    // Construct the string
    string description = "Graph with " + std::to_string(matrix.size()) + " vertices and " + to_string(edges) + " edges.";
    return description;
}

// Return the size
unsigned int Graph::size() const{
    return matrix.size();
}

// Get the edge
const int Graph::getEdge(unsigned int x, unsigned int y) const{

    // Check if x and y are within the bounds of the matrix
    if (x >= matrix.size() || y >= matrix[0].size()) {
        throw out_of_range("Index out of range");
    }

    return matrix[x][y];
}

// Get the vertex how are not 0
vector<unsigned int> Graph::getConnectedVertices(unsigned int vertex) const {

    vector<unsigned int> connectedVertices;

    // Check the bound
    if (vertex >= matrix.size()) {
        throw out_of_range("Vertex index out of range");
    }

    // Find the edges
    const vector<int>& edges = matrix[vertex];
    for (unsigned int i = 0; i < edges.size(); ++i) {
        if (edges[i] != 0) {
            connectedVertices.push_back(i);
        }
    }

    // Return the connected vertexes
    return connectedVertices;
}


/// Project 2 ///

string Graph::printGraph() const {
    string str = "";
    for(unsigned  int i = 0; i < matrix.size(); i++){
        str += "[";
        for(unsigned  int j = 0; j < matrix.size(); j++){
            str += to_string(matrix[i][j]) + ", ";
        }

        // Erase the last 2 chars
        str.erase(str.size() - 2);

        // In order to make use "\n" won't be at the end
        if(i != matrix.size() - 1){
            str += "]\n";
        }
        else{
            str += "]";
        }
    }
    return str;
}

Graph Graph::operator+(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

Graph& Graph::operator+=(const Graph& other){

    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }

    return *this;
}

Graph& Graph::operator+() {
    return *this;
}

Graph Graph::operator++() const {

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform addition per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 0){
                result.matrix[i][j] = matrix[i][j] + 1;
            }
            else{
                result.matrix[i][j] = 0;
            }
        }
    }
    return result;
}

Graph Graph::operator-(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

Graph& Graph::operator-=(const Graph& other){

    if (matrix.size() != other.matrix.size()) {
        throw std::invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }

    return *this;
}

Graph& Graph::operator-() {

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] = (-1) * matrix[i][j];
        }
    }

    return *this;
}

Graph Graph::operator--() const {

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    // Perform subtraction per element
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 0){
                result.matrix[i][j] = matrix[i][j] - 1;
            }
            else{
                result.matrix[i][j] = 0;
            }
        }
    }
    return result;
}

Graph& Graph::operator*(int factor){
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] = matrix[i][j] * factor;
        }
    }

    return *this;

}

Graph& Graph::operator/=(int factor){
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            matrix[i][j] = matrix[i][j] / factor;
        }
    }

    return *this;
}

Graph Graph::operator*=(const Graph& other) const {

    // Check if the two graphs have the same size
    if (matrix.size() != other.matrix.size()) {
        throw invalid_argument("Invalid operation: Graphs must have the same dimensions for addition.");
    }

    // Create a new graph to store the result
    Graph result;
    result.matrix.resize(matrix.size(), vector<int>(matrix.size(), 0));

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            for (int k = 0; k < matrix.size(); ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    os << graph.printGraph();
    return os;
}
