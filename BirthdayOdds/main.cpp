#include <iostream>
#include <random>
#include <ctime>
using namespace std;

bool method(int numPeople){
    int array[numPeople];

    for(int i = 0;i < numPeople;i++){
        array[i] = rand()%365;
    }

    for(int i : array)
        cout << i << endl;

    for(int i=0;i<numPeople;i++){
        for(int j=(i + 1);j<numPeople;j++){
            if(array[i] == array[j]){
                cout << array[i] << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    srand(time(0));
    string numPeopleString;
    int numPeople = 1;
    int numTries = -1;
    do{
        cout<<"Number of people in the room (or 0 to exit or -1 to go to different program): ";
        cin>>numPeopleString;
        numPeople = stoi(numPeopleString);
        if(numPeople == -1){
            //this part of program will go through multiple iterations and return results
            cout<<"Number of people in the room (will return to original program after one trial): ";
            cin>>numPeopleString;
            numPeople = stoi(numPeopleString);
            cout<<"Number of iterations (or -1 for special bamboozle): ";
            cin>>numPeopleString;
            numTries = stoi(numPeopleString);
            if(numTries == -1){
                int counter = 0;
                int numTrue = 0;
                do{
                    numTrue = 0;
                    for(int i = 0;i < 100000;i++){
                        bool temp = method(numPeople);
                        if(temp == true){
                            numTrue++;
                        }
                    }
                    counter++;
                }while(numTrue == 100000);
                cout<<"It took "<<counter<<" tries before it wasn't a 100% in a sample of 100,000 iterations"<<endl;
            }
            else{
                int numTrue = 0;
                for(int i = 0;i < numTries;i++){
                    bool temp = method(numPeople);
                    if(temp == true){
                        numTrue++;
                    }
                }
                cout<<"Returned true "<<numTrue<<" out of "<<numTries<<" tries."<<endl;
            }
        }
        else{
            bool temp = method(numPeople);
            if(temp == true)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
    }while(numPeople != 0);
}