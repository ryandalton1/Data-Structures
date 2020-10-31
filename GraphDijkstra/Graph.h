//
// Created by ryand on 11/7/2018.
//

#ifndef GRAPHRETRY_GRAPH_H
#define GRAPHRETRY_GRAPH_H
#include <vector>
#include <iostream>
using namespace std;

struct vertex; //just so that adjVertex will have access to vertex
struct adjVertex{
    vertex *v;//v points to the adjacent vertex
    int weight;
};

struct vertex{
    string name;
    vector<adjVertex> adj;
    int distance;

    vertex(string n){
        name = n;
    }
};

class Graph {
public:
    Graph();
    ~Graph();
    void addEdge(string,string,int);
    void addVertex(string);
    void displayEdges();
    void distanceBetween(string,string);
    void peopleNHopsAway(string,int);
    void testCases();
private:
    vector<vertex> vertices;
    vertex* search(string);
};


#endif //GRAPHRETRY_GRAPH_H
