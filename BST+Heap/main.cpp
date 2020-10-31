#include <iostream>
#include "MovieTree.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    MovieTree movieTree;
    //begin program by filling array with txt file information
    int movieQuantity = 0;
    ifstream myfiletemp(argv[1]);
    string input;
    while(getline(myfiletemp, input)){
        movieQuantity++;
    }
    ifstream myfile(argv[1]);
    while(getline(myfile, input)) {
        stringstream ss(input);
        //declare variables for every Item
        string ranking, title, year, quantity;
        getline(ss, ranking, ',');
        getline(ss, title, ',');
        getline(ss, year, ',');
        getline(ss, quantity);
        cout<<ranking<<title<<year<<quantity<<endl;
        //this is adding a line of the txt file, aka one movie to the array
        movieTree.addMovieNode(stoi(ranking), title, stoi(year), stoi(quantity),movieQuantity);
    }

    /*//test cases
    try{
        //test cases
        cout<<"Finding a movie - Whiplash"<<endl;
        movieTree.findMovie("Whiplash");

        cout<<"Finding a movie - ADADADAD"<<endl;
        movieTree.findMovie("ADADADAD");

        cout<<"Renting a movie - Whiplash"<<endl;
        movieTree.rentMovie("Whiplash");

        cout<<"Renting a movie - Forrest Gump"<<endl;
        movieTree.rentMovie("Forrest Gump");

        cout<<"Renting a movie - ADADADAD"<<endl;
        movieTree.rentMovie("ADADADAD");

        cout<<"Deleting a movie - Whiplash"<<endl;
        movieTree.deleteMovieNode("Whiplash");
        cout<<"Deleting a movie - ADADADAD"<<endl;
        movieTree.deleteMovieNode("ADADADAD");
        cout<<"Tree contains: "<<movieTree.countMovieNodes()<<" movies."<<endl;

        cout<<"Printing movies A-Z"<<endl;
        movieTree.printBetween('A', 'Z', movieQuantity);

        cout<<"Printing movies Z-A"<<endl;
        movieTree.printBetween('Z', 'A', movieQuantity);
    }
    catch (...){
        cout<<"Default exception"<<endl;
    }*/

    string controllerString;
    int controller = -1;
    do{
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Delete a movie"<<endl;
        cout<<"5. Count the movies"<<endl;
        cout<<"6. Print top 10 movies between two letters"<<endl;
        cout<<"7. Quit"<<endl;
        cout<<"Please enter your selection: ";
        getline(cin,controllerString);
        controller = stoi(controllerString);

        switch(controller){
            case 1:{
                string title;
                cout<<"Enter title (case-sensitive): ";
                getline(cin, title);
                movieTree.findMovie(title);
                break;
            }
            case 2:{
                string title;
                cout<<"Enter title (case-sensitive): ";
                getline(cin, title);
                movieTree.rentMovie(title);
                break;
            }
            case 3:{
                movieTree.printMovieInventory();
                break;
            }
            case 4:{
                string title;
                cout<<"Enter title (case-sensitive): ";
                getline(cin, title);
                movieTree.deleteMovieNode(title);
                break;
            }
            case 5:{
                cout<<"Tree contains: "<<movieTree.countMovieNodes()<<" movies."<<endl;
                break;
            }
            case 6:{
                string first, second;
                cout<<"Enter first letter (capital): ";
                getline(cin, first);
                cout<<"Enter second letter (capital): ";
                getline(cin, second);
                char firstLetter = first[0];
                char secondLetter = second[0];
                movieTree.printBetween(firstLetter, secondLetter, movieQuantity);
                break;
            }
            case 7:{
                cout<<"Goodbye!"<<endl;
                break;
            }
        }
    }while(controller != 7);
}