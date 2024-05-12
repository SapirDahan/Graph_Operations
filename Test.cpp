/*
 * Test program for Exercise 2.
 * Author: Benjamin Saldman.
 *
 * Edit: Sapir Dahan
 * ID: 325732972
 * Mail: sapirdahan2003@gmail.com
 */

#include "doctest.h"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g1 += g2;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g1 = ++g1;
    CHECK(g1.printGraph() == "[0, 3, 2]\n[3, 0, 4]\n[2, 4, 0]");

    +g1;
    CHECK(g1.printGraph() == "[0, 3, 2]\n[3, 0, 4]\n[2, 4, 0]");

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g4.loadGraph(graph4);

    CHECK_THROWS(g4 + g1);
    CHECK_THROWS(g1 + g4);

}

TEST_CASE("Test graph subtraction"){
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[0, 0, -1]\n[0, 0, -1]\n[-1, -1, 0]");

    g1 -= g2;
    CHECK(g1.printGraph() == "[0, 0, -1]\n[0, 0, -1]\n[-1, -1, 0]");

    g1 = --g1;
    CHECK(g1.printGraph() == "[0, 0, -2]\n[0, 0, -2]\n[-2, -2, 0]");

    -g1;
    CHECK(g1.printGraph() == "[0, 0, 2]\n[0, 0, 2]\n[2, 2, 0]");

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g4.loadGraph(graph4);

    CHECK_THROWS(g4 - g1);
    CHECK_THROWS(g1 - g4);

}

TEST_CASE("Test graph multiplication"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 * g2;

    CHECK(g3.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");

    g1*=g2;
    CHECK(g1.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g4.loadGraph(graph4);

    // Not the same size
    CHECK_THROWS(g1 * g4);
    CHECK_THROWS(g4 * g1);
    CHECK_THROWS(g1 *= g4);
    CHECK_THROWS(g4 *= g1);
}

TEST_CASE("Test graph division and multiplication by scalar"){
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1 * 3;

    CHECK(g2.printGraph() == "[0, 3, 0, 6]\n[3, 0, 3, 15]\n[6, 9, 0, 3]\n[0, 3, 27, 0]");

    g1 = g2 / 3;

    CHECK(g1.printGraph() == "[0, 1, 0, 2]\n[1, 0, 1, 5]\n[2, 3, 0, 1]\n[0, 1, 9, 0]");

    CHECK_THROWS(g1 = g2 / 0);

    // The same but with /= and *=
    g1 *= 3;

    CHECK(g1.printGraph() == "[0, 3, 0, 6]\n[3, 0, 3, 15]\n[6, 9, 0, 3]\n[0, 3, 27, 0]");

    g1 /= 3;

    CHECK(g1.printGraph() == "[0, 1, 0, 2]\n[1, 0, 1, 5]\n[2, 3, 0, 1]\n[0, 1, 9, 0]");

    CHECK_THROWS(g1 /= 0);
}

TEST_CASE("Test graph comparison"){

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 9, 0}};
    g2.loadGraph(graph2);

    CHECK((g1 == g2));
    CHECK((g2 == g1));


    ariel::Graph g3;
    vector<vector<int>> graph3 = {
            {0, 1, 0, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 19, 0}};
    g3.loadGraph(graph3);

    CHECK((g1 != g3));
    CHECK((g3 != g1));

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
            {0, 1, 7, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 1, 19, 0}};
    g4.loadGraph(graph4);

    CHECK((g3 < g4));
    CHECK((g3 <= g4));

    CHECK((g4 > g3));
    CHECK((g4 >= g3));

    CHECK(!(g3 > g4));

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
            {0, 1, 0},
            {1, 0, 1},
            {2, 3, 0}};
    g5.loadGraph(graph5);

    CHECK((g5 < g3));
    CHECK(!(g5 > g3));

    ariel::Graph g6;
    vector<vector<int>> graph6 = {
            {0, 1, 2},
            {1, 0, 5},
            {0, 1, 0}};
    g6.loadGraph(graph6);

    CHECK((g6 < g3));
    CHECK(!(g6 > g3));

    ariel::Graph g7;
    vector<vector<int>> graph7 = {
            {0, 5},
            {1, 0}};
    g7.loadGraph(graph7);

    CHECK((g7 < g3));
    CHECK(!(g7 > g3));

    ariel::Graph g8;
    vector<vector<int>> graph8 = {
            {0, 1, 1, 2},
            {1, 0, 1, 5},
            {2, 3, 0, 1},
            {0, 11, 19, 0}};
    g8.loadGraph(graph8);

    CHECK(!(g8 > g3));
    CHECK(!(g8 < g3));
    CHECK(!(g8 == g3));
    CHECK((g8 != g3));

}