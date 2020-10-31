//
// Created by ryand on 11/7/2018.
//

#include "Graph.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Graph::Graph(){
    cout<<"Creating object Graph"<<endl;
}

Graph::~Graph(){
    //dtor
}

void Graph::addEdge(string v1, string v2, int weight){
    if(v1 == v2){
        cout<<"Please enter two different cities"<<endl;
        return;
    }

    //search through vertices for the first city
    for(int i=0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            //we've found the first city now find the second
            for(int j=0; j < vertices.size(); j++){
                if(vertices[j].name == v2){
                    //now i is index of first city and j is index of second city
                    adjVertex av; //creating a new struct representing the adjacent city that will be added to the vertex
                    av.v = &vertices[j]; //now this is a struct containing just a pointer to the second city
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    break; //so created a pointer to second city and added it to first city adjacent list
                }
            }
        }
    }
}
void Graph::addVertex(string name){
    bool found = false;
    //we check if the vertex already exists
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == name)
            found = true;
    }
    //if found is true then exit method
    if(found == true){
        cout<<"City already exists"<<endl;
    }
    else{
        //if not found then create a vertex(city) then add it to vertices
        vertex v(name);
        vertices.push_back(v);
    }
}
void Graph::displayEdges(){
    //loop through all vertices and display them then their edges
    for(int i=0; i<vertices.size();i++){
        cout<<vertices[i].name<<"--->";
        for(int j=0; j<vertices[i].adj.size();j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }
}
vertex* Graph::search(string name){
    vertex* pointer = NULL;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            //we've found the first city so go through the array again for the second city
            pointer = &vertices[i];
            return pointer;
        }
    }
    return pointer;
}
class myComparator{
public:
    int operator() (const vertex* g1, const vertex* g2){
        return g1->distance > g2->distance;
    }
};
void Graph::peopleNHopsAway(string v1,int numHops){
    vertex* vertex1 = search(v1);
    //error check
    if(vertex1 == NULL){
        cout<<"This first person does not exist"<<endl;
        return;
    }
    //set all distances to infinity
    for(int i=0;i<vertices.size();i++){
        vertices[i].distance = 2147483647;
    }
    //create a queue and put source in, with distance of 0
    priority_queue <vertex*, vector<vertex*>, myComparator > pq;
    vertex1->distance = 0;
    pq.push(vertex1);
    while(!pq.empty()){
        //pop everything from queue (where you will always pop the smallest path)
        vertex* u = pq.top();
        pq.pop();
        //go through the popped name and check it's adjacent vertices for the smallest distance
        for(int i=0;i<u->adj.size();i++){
            //if there is a shorter path to adjacent name through u
            if(u->adj[i].v->distance > (u->distance + 1)){
                u->adj[i].v->distance = (u->distance + 1);
                pq.push(u->adj[i].v);
            }
        }
    }
    //at this point every name will have a distance associated with it from v1 so print distance of v2
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].distance == numHops){
            cout<<vertices[i].name<<endl;
        }
    }
}
void Graph::distanceBetween(string v1,string v2){
    //set vertex1 to the first argument
    vertex* vertex1 = search(v1);
    //error check
    if(vertex1 == NULL){
        cout<<"This first person does not exist"<<endl;
        return;
    }
    //set all distances to infinity
    for(int i=0;i<vertices.size();i++){
        vertices[i].distance = 2147483647;
    }
    //create a queue and put source in, with distance of 0
    priority_queue <vertex*, vector<vertex*>, myComparator > pq;
    vertex1->distance = 0;
    pq.push(vertex1);
    while(!pq.empty()){
        //pop everything from queue (where you will always pop the smallest path)
        vertex* u = pq.top();
        pq.pop();
        //go through the popped name and check it's adjacent vertices for the smallest distance
        for(int i=0;i<u->adj.size();i++){
            //if there is a shorter path to adjacent name through u
            if(u->adj[i].v->distance > (u->distance + u->adj[i].weight)){
                u->adj[i].v->distance = (u->distance + u->adj[i].weight);
                pq.push(u->adj[i].v);
            }
        }
    }
    //at this point every name will have a distance associated with it from v1 so print distance of v2
    vertex* vertex2 = search(v2);
    if(vertex2 == NULL){
        cout<<"The second name was not found"<<endl;
        return;
    }

    if(vertex2->distance == 2147483647){
        cout<<"No path between them found"<<endl;
        return;
    }

    cout<<"The shortest distance between "<<v1<<" and "<<v2<<" is "<<vertex2->distance<<endl;
}
void Graph::testCases(){
    cout<<"Printing all people and who they're adjacent to"<<endl;
    displayEdges();

    cout<<"Printing distance between two people next to each other in same group - Timothy and Simon"<<endl;
    distanceBetween("Timothy", "Simon");
    cout<<"Printing distance between two people in same group not adjacent - Kylie and Nathan"<<endl;
    distanceBetween("Kylie", "Nathan");
    cout<<"Printing distance between two people in different groups - Kylie and Sam"<<endl;
    distanceBetween("Kylie", "Sam");
    cout<<"Printing distance between two people, one real and one fake - Paramvir and Rio"<<endl;
    distanceBetween("Paramvir", "Rio");
    cout<<"Printing distance between two people, one fake and one real - Hope and Ryan"<<endl;
    distanceBetween("Hope", "Ryan");
    cout<<"Printing distance between two fake people - Aiden and Rodger"<<endl;
    distanceBetween("Aiden", "Rodger");

    cout<<"Printing people who are 1 hop away from a real person - Connor"<<endl;
    peopleNHopsAway("Connor", 1);
    cout<<"Printing people who are 2 hops away from a real person - Connor"<<endl;
    peopleNHopsAway("Connor", 2);
    cout<<"Printing people who are a overly large number of hops away 10 from a real person - Connor"<<endl;
    peopleNHopsAway("Connor", 10);
    cout<<"Printing people who are 1 hop away from a fake person - Ropo"<<endl;
    peopleNHopsAway("Ropo", 1);
    cout<<"Printing people who are 2 hops away from a fake person - Ropo"<<endl;
    peopleNHopsAway("Ropo", 2);
    cout<<"Printing people who are a overly large number of hops away 10 from a fake person - Ropo"<<endl;
    peopleNHopsAway("Ropo", 10);

    cout<<"Printing all people and who they're adjacent to if there is no graph"<<endl;
    vertices.clear();
    displayEdges();
}