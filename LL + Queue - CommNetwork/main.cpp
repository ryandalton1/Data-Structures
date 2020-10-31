#include <iostream>
#include <fstream>
#include "CommunicationNetwork.h"
using namespace std;

//Global Variables
CommunicationNetwork cn(10);

int main(int argc, char *argv[]) {
    //setup start program and store message in array
    int messageIndex = 0;
    string message[100];
    ifstream myfile(argv[1]);
    string word;
    int numWords = 0;
    while(myfile >> word){
        message[numWords] = word;
        numWords++;
    }
    //message is filled with all the words from the input file
    //Start program
    int controller = 0;
    string controllerString = "";
    do{
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path"<<endl;
        cout<<"3. Enqueue"<<endl;
        cout<<"4. Dequeue"<<endl;
        cout<<"5. Print Queue"<<endl;
        cout<<"6. Send Entire Message"<<endl;
        cout<<"7. Quit"<<endl;
        cout<<"Please enter your selection: ";
        getline(cin,controllerString);
        controller = stoi(controllerString);

        switch(controller){
            case 1: {
                cn.buildNetwork();
                break;
            }
            case 2: {
                cn.printPath();
                break;
            }
            case 3: {
                if(!cn.queueIsFull()){
                    cout<<"Enqueue next word in file..."<<endl;
                    cn.enqueue(message[messageIndex]);
                    messageIndex++;
                }
                else{
                    cout<<"Queue is full"<<endl;
                }
                break;
            }
            case 4: {
                if(cn.queueIsEmpty()){
                    cout<<"Queue is empty"<<endl;
                }
                else{
                    cn.dequeue();
                }
                break;
            }
            case 5: {
                cn.printQueue();
                break;
            }
            case 6: {
                while(messageIndex != numWords){
                    if(cn.queueIsFull()){
                        cn.sendQueue();
                    }
                    cn.enqueue(message[messageIndex]);
                    messageIndex++;
                }
                cn.sendQueue();
                break;
            }
            case 7: {
                cout<<"Goodbye!"<<endl;
                break;
            }
        }
    }while(controller != 7);
}