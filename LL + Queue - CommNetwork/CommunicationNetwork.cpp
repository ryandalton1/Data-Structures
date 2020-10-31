//
// Created by ryand on 10/9/2018.
//

#include "CommunicationNetwork.h"
#include <iostream>
using namespace std;

void CommunicationNetwork::enqueue(string word){
    if(queueIsFull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        if(queueTail == (queueSize - 1) && queueHead != 0){
            queueTail = -1;
        }
        queueTail++;
        arrayQueue[queueTail] = word;
        if(queueHead == -1){
            queueHead = 0;
        }
    }


    cout<<"E: "<<word<<endl;
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
}

void CommunicationNetwork::dequeue(){
    if(queueHead == -1 && queueTail == -1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        //to begin dequeue transmit what was stored in the queue, set that slot to nothing and increment head
        transmitMsg(arrayQueue[queueHead]);
        arrayQueue[queueHead] = "";
        queueHead++;
        //this condition tells if tail and head were the same, if it is the case start the queue over
        if((queueHead - 1) == queueTail){
            queueHead = -1;
            queueTail = -1;
        }
        //this condition tells us if the head was at the end of the queue, in that case send head to the front
        else if(queueHead == queueSize){
            queueHead = 0;
        }

    }

    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
}

void CommunicationNetwork::printQueue(){
    if(queueHead == -1 && queueTail == -1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        int tempHead = queueHead;
        while(tempHead != queueTail){
            cout<<tempHead<<": "<<arrayQueue[tempHead]<<endl;
            tempHead++;
        }
    }
}

void CommunicationNetwork::sendQueue(){
    //i is just a counter for how many times to dequeue before being done
    int i = queueHead;
    //if head is less than tail run through queue until tail dequeuing everything
    if(queueHead <= queueTail){
        while(i <= queueTail){
            dequeue();
            i++;
        }
    }
    //if head is more than tail run from head to the end of list than from start to tail
    else{
        while(i <= (queueSize - 1)){
            dequeue();
            i++;
        }
        i = 0;
        while(i <= queueTail){
            dequeue();
            i++;
        }
    }
    queueHead = -1;
    queueTail = -1;
}

bool CommunicationNetwork::queueIsFull(){
    return((queueTail == (queueSize - 1) && queueHead == 0) || (queueHead == queueTail + 1));
}

bool CommunicationNetwork::queueIsEmpty(){
    return(queueHead == -1 && queueTail == -1);
}

void CommunicationNetwork::buildNetwork(){
    City *LosAngeles = new City("Los Angeles", NULL, NULL, "");
    City *Phoenix = new City("Phoenix", NULL, LosAngeles, "");
    City *Denver = new City("Denver", NULL, Phoenix, "");
    City *Dallas = new City("Dallas", NULL, Denver, "");
    City *StLouis = new City("St Louis", NULL, Dallas, "");
    City *Chicago = new City("Chicago", NULL, StLouis, "");
    City *Atlanta = new City("Atlanta", NULL, Chicago, "");
    City *WashingtonDC = new City("Washington DC", NULL, Atlanta, "");
    City *NewYork = new City("New York", NULL, WashingtonDC, "");
    City *Boston = new City("Boston", NULL, NewYork, "");
    LosAngeles->next = Phoenix;
    Phoenix->next = Denver;
    Denver->next = Dallas;
    Dallas->next = StLouis;
    StLouis->next = Chicago;
    Chicago->next = Atlanta;
    Atlanta->next = WashingtonDC;
    WashingtonDC->next = NewYork;
    NewYork->next = Boston;

    head = LosAngeles;
    printPath();
}

void CommunicationNetwork::printPath(){
    if(head == NULL){
        cout << "===CURRENT PATH===" << endl;
        cout << "NULL"<<endl;
        cout << "==================" << endl;
    }
    else {
        cout << "===CURRENT PATH===" << endl;
        cout << "NULL";
        cout << " <- ";
        City *current = head;
        while (current->next != NULL) {
            cout << current->cityName;
            cout << " <-> ";
            current = current->next;
        }
        cout << current->cityName;
        cout << " -> NULL" << endl;
        cout << "==================" << endl;
    }
}

void CommunicationNetwork::transmitMsg(string msg){
    City *current = head;
    current -> message = msg;
    while(current -> next != NULL){
        cout<<current -> cityName<<" received "<<current -> message<<endl;
        current -> next -> message = current -> message;
        current -> message = "";
        current = current -> next;
    }
    while(current != head){
        cout<<current -> cityName<<" received "<<current -> message<<endl;
        current -> previous -> message = current -> message;
        current -> message = "";
        current = current -> previous;
    }
    cout<<current -> cityName<<" received "<<current -> message<<endl;
    return;
}

CommunicationNetwork::CommunicationNetwork(int qs){
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = -1;
    queueTail = -1;
}