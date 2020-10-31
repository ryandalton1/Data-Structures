//Program was writtin by Ryan Dalton for 2275
//Assignment 2
#include <iostream>
#include<sstream>
#include<fstream>
using namespace std;

class Item{
    public:
        int serialNumber;
        string name;
        string publishedDate;
        int price;
        string type;
    void print_details(){
        cout<<"This is a "<<type<<endl;
        cout<<"Serial Number: "<<serialNumber<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Published Date: "<<publishedDate<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class Book : public Item{
    public:
        int ISBN;
        int numPages;
        string genre;
        void print_details(){
            Item::print_details();
            cout<<"ISBN: "<<ISBN<<endl;
            cout<<"Number of pages: "<<numPages<<endl;
            cout<<"Genre: "<<genre<<endl;
        }
};

class Magazine : public Item{
    public:
        string area, freqOfPub;
    void print_details(){
        Item::print_details();
        cout<<"Frequency of publishing: "<<freqOfPub<<endl;
        cout<<"Local or International: "<<area<<endl;
    }
};

class CD : public Item{
    public:
        string playTime;
        string description;
    void print_details(){
        Item::print_details();
        cout<<"Play time: "<<playTime<<endl;
        cout<<"Description: "<<description<<endl;
    }
};

Book books[100];
Magazine magazines[100];
CD cds[100];
int cur_books = 0;
int cur_magazines = 0;
int cur_cds = 0;

void search(int serialNumber){
    int controller = 0;
    for(Book b: books){
        if(b.serialNumber == serialNumber){
            b.print_details();
            controller = -1;
        }
    }
    if(controller != -1){
        for(Magazine m: magazines){
            if(m.serialNumber == serialNumber){
                m.print_details();
                controller = -1;
            }
        }
    }
    if(controller != -1){
        for(CD c: cds){
            if(c.serialNumber == serialNumber){
                c.print_details();
                controller = -1;
            }
        }
    }
    if(controller == 0){
        cout<<"Not found"<<endl;
    }
}

//function will take data for a book, magazine, or CD and put it in the right array
void insert(string data){
    //takes the line of data containing info on serial number, price, etc... makes a stringstream from it
    stringstream ss(data);
    string serialNumber, name, publishedDate, type, price;
    getline(ss, serialNumber, ',');
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, publishedDate, ',');
    getline(ss, price, ',');
    //have made the general variables for all items. Now make variables depending on item
    if(type == "Book"){
        string ISBN, numPages, genre;
        getline(ss, ISBN, ',');
        getline(ss, numPages, ',');
        getline(ss, genre, ',');
        //now all the variables are set and I need to input this into an array
        books[cur_books].serialNumber = stoi(serialNumber);
        books[cur_books].type = type;
        books[cur_books].name = name;
        books[cur_books].publishedDate = publishedDate;
        books[cur_books].price = stoi(price);
        books[cur_books].ISBN = stoi(ISBN);
        books[cur_books].numPages = stoi(numPages);
        books[cur_books].genre = genre;
        cur_books++;
    }
    else if(type == "Magazine"){
        string freqOfPub, area;
        getline(ss, freqOfPub, ',');
        getline(ss, area, ',');
        //now all the variables are set and I need to input this into an array
        magazines[cur_magazines].serialNumber = stoi(serialNumber);
        magazines[cur_magazines].type = type;
        magazines[cur_magazines].name = name;
        magazines[cur_magazines].publishedDate = publishedDate;
        magazines[cur_magazines].price = stoi(price);
        magazines[cur_magazines].freqOfPub = stoi(freqOfPub);
        magazines[cur_magazines].area = stoi(area);
        cur_magazines++;
    }
    else{
        string playTime, description;
        getline(ss, playTime, ',');
        getline(ss, description, ',');
        //now all the variables are set and I need to input this into an array
        cds[cur_cds].serialNumber = stoi(serialNumber);
        cds[cur_cds].type = type;
        cds[cur_cds].name = name;
        cds[cur_cds].publishedDate = publishedDate;
        cds[cur_cds].price = stoi(price);
        cds[cur_cds].playTime = playTime;
        cds[cur_cds].description = description;
        cur_cds++;
    }
    //at this point code will have found what item is being inserted and put it in the right array
}

void remove(int serialNumber){
    cout<<"Entered remove function, s# is: "<<serialNumber<<endl;
    int controller = 0;
    for(int i = 0;i<=100;i++){
        if(books[i].serialNumber == serialNumber){
            for(int x = i;x <= (cur_books - 2);x++){
                books[x] = books[x+1];
            }
            cur_books--;
            controller = -1;
        }
    }
    if(controller != -1){
        for(int i = 0;i<=100;i++){
            if(magazines[i].serialNumber == serialNumber){
                for(int x = i;x <= (cur_magazines - 2);x++){
                    magazines[x] = magazines[x+1];
                }
                cur_magazines--;
                controller = -1;
            }
        }
    }
    if(controller != -1){
        for(int i = 0;i<=100;i++){
            if(cds[i].serialNumber == serialNumber){
                for(int x = i;x <= (cur_cds - 2);x++){
                    cds[x] = cds[x+1];
                }
                cur_cds--;
                controller = -1;
            }
        }
    }
    if(controller == 0){
        cout<<"Not found"<<endl;
    }
}

int main(int argc, char *argv[]) {
    ifstream myfile(argv[1]);
    string input;
    while(getline(myfile, input)){
        stringstream ss(input);
        //declare variables for every Item
        string serialNumber, name, publishedDate, type, price;
        getline(ss, serialNumber, ',');
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, publishedDate, ',');
        getline(ss, price, ',');
        //now see if the read line is of which type
        if(type == "Book"){
            string ISBN, numPages, genre;
            getline(ss, ISBN, ',');
            getline(ss, numPages, ',');
            getline(ss, genre, ',');
            //now all the variables are set and I need to input this into an array
            books[cur_books].serialNumber = stoi(serialNumber);
            books[cur_books].type = type;
            books[cur_books].name = name;
            books[cur_books].publishedDate = publishedDate;
            books[cur_books].price = stoi(price);
            books[cur_books].ISBN = stoi(ISBN);
            books[cur_books].numPages = stoi(numPages);
            books[cur_books].genre = genre;
            cur_books++;
        }
        else if(type == "Magazine"){
            string freqOfPub, area;
            getline(ss, freqOfPub, ',');
            getline(ss, area, ',');
            //now all the variables are set and I need to input this into an array
            magazines[cur_magazines].serialNumber = stoi(serialNumber);
            magazines[cur_magazines].type = type;
            magazines[cur_magazines].name = name;
            magazines[cur_magazines].publishedDate = publishedDate;
            magazines[cur_magazines].price = stoi(price);
            magazines[cur_magazines].freqOfPub = freqOfPub;
            magazines[cur_magazines].area = area;
            cur_magazines++;

        }
        else{
            string playTime, description;
            getline(ss, playTime, ',');
            getline(ss, description, ',');
            //now all the variables are set and I need to input this into an array
            cds[cur_cds].serialNumber = stoi(serialNumber);
            cds[cur_cds].type = type;
            cds[cur_cds].name = name;
            cds[cur_cds].publishedDate = publishedDate;
            cds[cur_cds].price = stoi(price);
            cds[cur_cds].playTime = playTime;
            cds[cur_cds].description = description;
            cur_cds++;
        }
    }
    myfile.close();
    //at this point there should be three arrays: books[], magazines[], cds[] filled with the items of the txt
    //so now take the second input file and read through it, performing various actions
    int lineSwitch = 0; //controller to switch what to do for each line
    int actionController = 0;
    ifstream secondFile(argv[2]);
    string secondInput;
    while(getline(secondFile, secondInput)){
        stringstream ss(secondInput);
        if(lineSwitch == 0){
            //meaning program is currently reading first line (1,2,or 3)
            string temp;
            getline(ss, temp); // read through the first line and assign temp 1,2,or 3
            actionController = stoi(temp); //assign that value to actionController
            lineSwitch = 1;
        }
        else{
            //enters this after reading the next line, and will know which action to do because of action controller
            //will call insert function
            if(actionController == 1){
                cout<<"Entered insert function"<<endl;
                string temp;
                getline(ss, temp);
                insert(temp);
            }
            //this will call if actionController is 2, meaning call remove function
            else if(actionController == 2){
                cout<<"Entered delete function"<<endl;
                string temp;
                getline(ss, temp);
                remove(stoi(temp));
            }
            //this will call if actionController is 3, meaning call search function
            else{
                cout<<"Entered search function"<<endl;
                string temp;
                getline(ss, temp);
                search(stoi(temp));
            }
            lineSwitch = 0;
            actionController = 0;
        }


    }
    secondFile.close();
    //at this point the code has gone through both files. made all three array and done the actions it needed to
    for(int i = 0;i<cur_books;i++){
        books[i].print_details();
    }
    for(int i = 0;i<cur_magazines;i++){
        magazines[i].print_details();
    }
    for(int i = 0;i<cur_cds;i++){
        cds[i].print_details();
    }
}