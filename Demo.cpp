/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 *
 * Edit: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */



#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout<<"g1: "<<endl;
    cout<<g1<<endl; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    cout<<endl;

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout<<"g3 = g1 + g2: "<<endl;
    cout<<g3<<endl;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
    cout<<endl;

    g1 *= -2;        // Multiply the graph by -2.
    cout<<"g1 *= -2: "<<endl;
    cout<<g1<<endl; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
    cout<<endl;

    g1 /= -2;
    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout<<"g4 = g1 * g2 (after g1 /= -2): "<<endl;
    cout<<g4<<endl;           // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]
    cout<<endl;

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    cout<<"g5 and g1 dont have the same dimension: "<<endl;
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "Invalid operation: Graphs must have the same dimensions for multiplication."
    }

    cout << endl;
    ariel::Graph g7;
    vector<vector<int>> graph7 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 19, 0}};
    g7.loadGraph(graph7);

    ariel::Graph g8;
    vector<vector<int>> graph8 = {
            {0, 1, 7, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 19, 0}};
    g8.loadGraph(graph8);

    cout<<"g7 < g8? ";
    if(g7<g8){ cout<<"yes"<<endl; }
    else{ cout<<"no"<<endl; }
    cout<<endl;

    g8++;
    cout<<"g8++: "<<endl;
    cout<<g8<<endl; // Should print: [0, 2, 8, 3], [2, 0, 2, 6], [3, 4, 0, 2], [0, 2, 20, 0]

}