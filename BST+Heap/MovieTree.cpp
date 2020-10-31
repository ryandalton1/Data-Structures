//
// Created by ryand on 10/18/2018.
//

#include "MovieTree.h"
#include <iostream>
using namespace std;

int count = 0;
//These methods are private, meaning they can only be called from within this .cpp
void MovieTree::heapPush(MovieNodeHeap *heap, MovieNodeHeap movie, int capacity, int *cSize){
    if (*cSize == capacity){
        cout<<"heap full"<<endl;
    }else{
        *cSize = *cSize + 1;
        int i = *cSize;
        heap[*cSize] = movie;
        //while the spot we're inserting at is more than one and the parent is more than the current value
        //switch the parent and the child
        while(i > 1 and heap[i/2].quantity <= heap[i].quantity){
            MovieNodeHeap temp = heap[i/2];
            heap[i/2] = heap[i];
            heap[i] = temp;
            i = i / 2;
        }

    }
}
void MovieTree::maxHeapify(MovieNodeHeap *heap, int *currentSize, int i){
    int left = 2*i;
    int right = 2*i + 1;
    int largest = i;
    if (left <= *currentSize and heap[left].quantity > heap[i].quantity){
        largest = left;
    }
    if(right <= *currentSize and heap[right].quantity > heap[largest].quantity){
        largest = right;
    }
    if(largest != i){
        MovieNodeHeap temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeapify(heap, currentSize, largest);
    }
}
MovieNodeHeap MovieTree::heapPop(MovieNodeHeap *heap, int capacity, int *cSize){
    MovieNodeHeap popVal;
    if (*cSize == 0){
        cout<<"empty"<<endl;
    }
    if(*cSize == 1) {
        *cSize = *cSize - 1;
        return heap[1];
    }else{
        popVal = heap[1];
        heap[1] = heap[*cSize];
        *cSize = *cSize - 1;
        maxHeapify(heap, cSize, 1);
    }
    return popVal;
}
void MovieTree::DeleteAll(MovieNodeBST * node){
    //this method will be called to delete all the nodes in the BST, aka #-Z
    //call deleteMovieNode(for every movie)
    if(node == NULL){
        return;
    }
    DeleteAll(node->leftChild);
    int sizeOfHeap = *node->currentSizePointer;
    for(int i = 1;i <= sizeOfHeap;i++){
        deleteMovieNode(node->heap[i].title);
    }
    DeleteAll(node->rightChild);
};
void MovieTree::printMovieInventory(MovieNodeBST * node){
    if(node == NULL){
        return;
    }
    printMovieInventory(node->leftChild);
    cout<<node->letter<<endl;
    for(int i = 1;i <= *node->currentSizePointer;i++){
        cout<<"Movie: "<<node->heap[i].title<<" "<<node->heap[i].quantity<<endl;
    }
    printMovieInventory(node->rightChild);
};
void MovieTree::countMovieNodes(MovieNodeBST *node){
    if(node == NULL){
        return;
    }
    countMovieNodes(node->leftChild);
    count = count + *node->currentSizePointer;
    countMovieNodes(node->rightChild);
};
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title){
    //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
    //if there is no BST or if root is the one, return it
    if(node == NULL){
        return NULL;
    }
    if(node->letter == title[0]){
        return node;
    }
        //if the letter we're looking for is greater than the current node move to the right
    else if(node->letter < title[0]){
        return searchBST(node->rightChild, title);
    }
        //else move the node to the left
    else{
        return searchBST(node->leftChild, title);
    }
};
MovieNodeHeap *MovieTree::searchHeap(MovieNodeBST* letterNode, std::string title, int* controller){
    //to search through a heap for a title, go through every element in the array and compare it to title
    MovieNodeHeap *returnedThing;
    for(int i = 1;i <= *letterNode->currentSizePointer;i++){
        if(letterNode->heap[i].title == title){
            returnedThing = &letterNode->heap[i];
            return returnedThing;
        }
    }
    *controller = 1;
};
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node){
    if(node->leftChild == NULL){
        return node;
    }

    treeMinimum(node->leftChild);
}; //use this to find the left most leaf node of the BST, you'll need this in the delete function
void MovieTree::addBSTNode(char letter,int heapSize){
    MovieNodeBST *newNode = new MovieNodeBST(letter, heapSize);
    MovieNodeBST *parent = NULL;
    MovieNodeBST *tmp = root;
    while(tmp != NULL){
        //enters while loop if there is a parent
        parent = tmp;
        if(newNode->letter < tmp->letter)
            tmp = tmp->leftChild;
        else
            tmp = tmp->rightChild;
    }//so when through while loop parent will point to a node that has an empty child spot for newNode
    if(parent == NULL){
        root = newNode;
    }
    else if(newNode->letter < parent->letter){
        parent->leftChild = newNode;
        newNode->parent = parent;
    }
    else{
        parent->rightChild = newNode;
        newNode->parent = parent;
    }
};
//this function needs to be given a letter node BST, and a letter of the node to delete. It will then use a
//recursive function to look through the tree and return the inital root
MovieNodeBST* MovieTree::deleteBSTNode(MovieNodeBST *node, char letter){
    //if empty return the original root
    if(node == NULL)
        return node;
    //this if statement will determine which part of the tree to go into
    if(letter < node->letter){
        node->leftChild = deleteBSTNode(node->leftChild, letter);
    }
    else if(letter > node->letter){
        node->rightChild = deleteBSTNode(node->rightChild, letter);
    }
        //this else statement will be entered when the node to be deleted is found
    else{
        if(node->leftChild == NULL){
            MovieNodeBST *tmp = node->rightChild;
            delete node;
            return tmp;
        }
        else if(node->rightChild == NULL){
            MovieNodeBST *tmp = node->leftChild;
            delete node;
            return tmp;
        }
        //will execute this code if there are two children, replacing the deleted node with the minimum in the right tree
        MovieNodeBST *tmp = treeMinimum(node->rightChild);
        node->letter = tmp->letter;
        node->rightChild = deleteBSTNode(node->rightChild,tmp->letter);
    }
    return node;
};
//=======================================================================================================
//These methods are public, meaning they can be called from main.cpp
MovieTree::MovieTree(){};
MovieTree::~MovieTree(){
    DeleteAll(root);
};
void MovieTree::printBetween(char firstLetter, char secondLetter,int heapSize){
    //pop each letter 10 times, then push them back in
    //heapPop(MovieNodeHeap *heap, int capacity, int *cSize)
    if(firstLetter > secondLetter){
        cout<<"Please enter two letters in order"<<endl;
        return;
    }
    do{
        MovieNodeHeap poppedMovies[10];
        cout<<firstLetter<<endl;
        string tempLetter;
        tempLetter[0] = firstLetter;
        MovieNodeBST *letterNode = searchBST(root,tempLetter);
        if(letterNode == NULL){

        }
        else{
            int counter = 0;
            while(*letterNode->currentSizePointer != 0 && counter != 10){
                MovieNodeHeap temp = heapPop(letterNode->heap, heapSize, letterNode->currentSizePointer);
                poppedMovies[counter] = temp;
                cout<<"Movie: "<<temp.title<<" "<<temp.quantity<<endl;
                counter++;
            }
            for(int i = 0;i < counter;i++){
                heapPush(letterNode->heap, poppedMovies[i], heapSize, letterNode->currentSizePointer);
            }
        }
        firstLetter++;
    }while(firstLetter != (secondLetter + 1));
}
void MovieTree::printMovieInventory(){
    printMovieInventory(root);
};
int MovieTree::countMovieNodes(){
    count = 0;
    countMovieNodes(root);
    return count;
};
void MovieTree::deleteMovieNode(string title)
{
    MovieNodeBST *letterNode = searchBST(root, title);
    if(letterNode == NULL){
        cout<<"Movie not found"<<endl;
        return;
    }
    int controller = 0;
    int *controllerPointer = &controller;
    MovieNodeHeap *temp = searchHeap(letterNode, title, controllerPointer);
    if(*controllerPointer == 1){
        cout<<"Movie not found"<<endl;
        return;
    }
    else{
        cout<<"Deleting... "<<temp->title<<endl;
        temp->quantity = 0;
        maxHeapify(letterNode->heap, letterNode->currentSizePointer, 1);
        if(letterNode->heap[1].quantity == 0){
            deleteBSTNode(root, title[0]);
        }
    }
}
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity, int heapSize){
    MovieNodeBST *letterNode = searchBST(root, title);
    //MovieNodeHeap movieIn = new MovieNodeHeap(ranking, title, releaseYear, quantity);
    MovieNodeHeap movieIn;
    movieIn.quantity = quantity;
    movieIn.title = title;
    movieIn.ranking = ranking;
    movieIn.year = releaseYear;

    if(letterNode == NULL){
        addBSTNode(title[0],heapSize);
        addMovieNode(ranking, title, releaseYear, quantity, heapSize); //just calls this function again
    }
    else{
        heapPush(letterNode->heap,movieIn,heapSize,letterNode->currentSizePointer);
    }
};
void MovieTree::findMovie(std::string title){
    MovieNodeBST *tmpBST = searchBST(root, title);
    if(tmpBST == NULL)
        cout<<"Movie not found"<<endl;
    else{
        cout<<"Found letterNode "<<tmpBST->letter<<endl;
        int controller = 0;
        int *controllerPointer = &controller;
        MovieNodeHeap *foundMovie = searchHeap(tmpBST, title,controllerPointer);
        if(*controllerPointer == 1){
            cout<<"Movie not found"<<endl;
        }
        else{
            cout<< "Movie Info:" <<endl;
            cout<< "============="<<endl;
            cout<< "Ranking: "<< foundMovie->ranking<<endl;
            cout<< "Title: "<<foundMovie->title<<endl;
            cout<< "Year: "<<foundMovie->year<<endl;
            cout<< "Quantity: "<<foundMovie->quantity<<endl;
        }
    }
};
void MovieTree::rentMovie(std::string title){
    MovieNodeBST *temp = searchBST(root, title);
    if(temp == NULL)
        cout<<"That movie isn't here"<<endl;
    else{
        int controller = 0;
        int *controllerPointer = &controller;
        MovieNodeHeap *foundMovie = searchHeap(temp, title,controllerPointer);
        if(*controllerPointer == 1)
            cout<<"Movie not found"<<endl;
        else{
            if(foundMovie->quantity == 0){
                cout<<"We are out of that movie, sorry"<<endl;
                return;
            }
            foundMovie->quantity--;
            maxHeapify(temp->heap, temp->currentSizePointer, 1);
            cout << "Movie has been rented." << endl;
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << foundMovie->ranking << endl;
            cout << "Title:" << foundMovie->title << endl;
            cout << "Year:" << foundMovie->year << endl;
            cout << "Quantity:" << foundMovie->quantity << endl;
        }
    }
};