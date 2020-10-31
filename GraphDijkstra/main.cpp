#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

int main(int arc, char *argv[]) {
    Graph g;

    string input;
    //this section will go through whole file and create a vertex for every name
    ifstream myfileVertices(argv[1]);
    while(getline(myfileVertices, input)) {
        stringstream ss(input);
        //declare variables for every Item
        string vertex;
        getline(ss, vertex, '-');
        g.addVertex(vertex);
    }
    //this section will go through whole file and add adjacent names for every vertex
    ifstream myfile(argv[1]);
    while(getline(myfile, input)) {
        stringstream ss(input);
        //declare variables for every Item
        string vertex;
        getline(ss, vertex, '-');

        string edge;
        string personWeight[2];
        int controller = 0;
        while(getline(ss, edge, ',')){
            if(controller == 0){
                stringstream ss2(edge);
                string temp;
                ss2>>temp;
                personWeight[0] = temp;
                controller = 1;
            }
            else if(controller == 1){
                stringstream ss2(edge);
                string temp;
                ss2>>temp;
                g.addEdge(vertex, personWeight[0], stoi(temp));
                controller = 0;
            }
        }
    }


    string controllerString;
    int controller = -1;
    do{
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Print list of people and their acquaintances"<<endl;
        cout<<"2. Print distance between 2 people"<<endl;
        cout<<"3. Print people who are 'n' hops away"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"5. Test Cases"<<endl;
        cout<<"Please enter your selection: ";
        getline(cin,controllerString);
        controller = stoi(controllerString);

        switch(controller){
            case 1:{
                g.displayEdges();
                break;
            }
            case 2:{
                string name1, name2;
                cout<<"Please enter the first person: ";
                getline(cin, name1);
                cout<<"Please enter the second person: ";
                getline(cin, name2);
                g.distanceBetween(name1, name2);
                break;
            }
            case 3:{
                string name1, numHopsString;
                cout<<"Please enter the first person: ";
                getline(cin, name1);
                cout<<"Please enter the number of hops: ";
                getline(cin, numHopsString);
                int numHops = stoi(numHopsString);
                g.peopleNHopsAway(name1, numHops);
                break;
            }
            case 4:{
                cout<<"Goodbye!"<<endl;
                break;
            }
            case 5:{
                g.testCases();
                break;
            }
        }
    }while(controller != 4);
}