#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include<string>
struct City{
    std::string cityName;
    std::string message; //intended to hold one word
    City *next;
    City *previous;

    City(std::string n, City *ne, City *p,std::string m){
        cityName = n;
        next = ne;
        previous = p;
        message = m;
    };
};

class CommunicationNetwork
{
    public:
        CommunicationNetwork(int);
        //virtual ~CommunicationNetwork();
        //circular queue methods
        void enqueue(std::string);
        void dequeue(); //should send through network, call transmit msg
        void printQueue();
        void sendQueue(); //dequeue the whole queue through the network
        void buildNetwork();
        void printPath();
        bool queueIsFull(); //send when full
        bool queueIsEmpty();
        void transmitMsg(std::string);

    protected:
    private:
        City *head;
        City *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H
